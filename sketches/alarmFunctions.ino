String setHour;
String setMin;
int HourVal;
int MinVal;
int flag = 0;
bool isPlaying = false;

DateTime setAlarm(DateTime current) {
  if (Serial.available() > 0) {
    setHour = Serial.readString();
    HourVal = setHour.toInt();
    while (Serial.available() == 0);
    setMin = Serial.readString();
    MinVal = setMin.toInt();
    DateTime future (current + TimeSpan(0, HourVal, MinVal, 0));
    Serial.print("Current time: ");
    Serial.print(current.hour());
    Serial.print(":");
    Serial.println(current.minute());
    Serial.print("Alarm set to: ");
    Serial.print(future.hour());
    Serial.print(":");
    Serial.println(future.minute());
    Serial.print("Song set for alarm is song number ");
    Serial.println(song_no);
    Serial.println("*");
    return (future);
  }
}

void playAlarm(DateTime current, DateTime future) {
  long startTime;
  if (current.minute() == future.minute() && current.hour() == future.hour() && current.second() == future.second()) {
    //Serial.println("Matched");
    startTime = millis();
    flag = 1;
  }
  if (millis() - startTime <= 60000 && flag == 1) {
    if (isPlaying == false) {
      myDFPlayer.play(song_no);
      isPlaying = true;
    }
  } else {
    myDFPlayer.pause();
    isPlaying = false;
    flag = 0;
  }
}
