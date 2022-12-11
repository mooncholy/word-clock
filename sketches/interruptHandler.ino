void increment_c_Counter() {                 //isr function
  //Delay to debounce push button
  static unsigned long lastInterrupt = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterrupt > 200) {
    colorMode++;
    //Serial.println(colorMode);
  }
  //isr handler function: loop through color modes
  if(colorMode > 3) {colorMode = 0;}
  //Serial.println(colorMode);
  lastInterrupt = interruptTime;
}

void increment_s_Counter() {                 //isr function
  temp = millis();
  //Delay to debounce push button
  static unsigned long lastInterrupt = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterrupt > 200) {
    song_no++;
    Serial.print("Song set for alarm is song number ");
    Serial.println(song_no);
    Serial.println("*");
    //song_flag = 1;
  }
  //isr handler function: loop through color modes
  if(song_no > 7) {song_no = 0;}
  //Serial.println(song_no);
  lastInterrupt = interruptTime;
}
