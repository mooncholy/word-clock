
#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include "RGB.h"
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

//Define RTC module
//char daysOfTheWeek[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
RTC_DS3231 rtc;

//Define RBG LED matrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 6,                             //width, height, Arduino pin
                            NEO_MATRIX_TOP + NEO_MATRIX_LEFT +                      //position of first LED in the matrix
                            NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE);              //specifies the direction of the matrix sequence

const int colorBTNpin = 2;    //color mode picker pin (interrupt pin)
volatile int colorMode;       //counter for color modes
RGB color;                    //color of LED neopixels
const int songPin = 3;        //alarm song picker pin (interrupt pin)
volatile int song_no;         //counter for songs

int temp;
int song_flag = 0;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(25);  //Set volume value. From 0 to 30
  //myDFPlayer.play(1);  //Play the first mp3
  
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, set time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  matrix.begin();      //initialize matrix display
  matrix.setBrightness(30);
  matrix.setTextColor(matrix.Color(255, 255, 255));
  matrix.setTextWrap(false);

  pinMode(colorBTNpin, INPUT_PULLUP);     //internal pullup resistor with push button

  colorMode = 0; //initial mode: white
  attachInterrupt(digitalPinToInterrupt(colorBTNpin), increment_c_Counter, FALLING);
  song_no = 1;
  attachInterrupt(digitalPinToInterrupt(songPin), increment_s_Counter, FALLING);
}

void loop() {
  if (colorMode == 0) {color = white;}
  else if (colorMode == 1) {color = red;}
  else if (colorMode == 2) {color = blue;}
  else if (colorMode == 3) {color = cyan;}
  
  DateTime current = rtc.now();
  displayTime(current, color);

  DateTime future = setAlarm(current);
  playAlarm(current, future);
}
