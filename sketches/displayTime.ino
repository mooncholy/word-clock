void displayTime(DateTime current, RGB color) {
  //DateTime current = rtc.now();
  ////Serial.print("It is ");
  if (current.minute() % 5 == 0) {  //turns off screen before each time the matrix changes time display
    matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
  }
  //checks minutes values
  if ((current.minute() > 4 && current.minute() < 10) || (current.minute() > 54)) {
    MFIVE(color);
    ////Serial.print("five");
  } else if ((current.minute() > 9 && current.minute() < 15) || (current.minute() > 49 && current.minute() < 55)) {
    MTEN(color);
    ////Serial.print("ten");
  } else if ((current.minute() > 14 && current.minute() < 20) || (current.minute() > 44 && current.minute() < 50)) {
    AQUARTER(color);
    ////Serial.print("a quarter");
  } else if ((current.minute() > 19 && current.minute() < 25) || (current.minute() > 39 && current.minute() < 45)) {
    TWENTY(color);
    ////Serial.print("twenty");
  } else if ((current.minute() > 24 && current.minute() < 30) || (current.minute() > 34 && current.minute() < 40)) {
    TWENTY(color);
    MFIVE(color);
    ////Serial.print("twenty five");
  } else if (current.minute() > 29 && current.minute() < 35) {
    HALF(color);
    ////Serial.print("half");
  }

  if (current.minute() < 5) {
    switch (current.hour()) {
      case 1:
      case 13:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          ONE(color);
        } else {
          scrollText("01:00 ", color);
        }
        ////Serial.print("one");
        break;
      case 2:
      case 14:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          TWO(color);
        } else {
          scrollText("02:00 ", color);
        }
        ////Serial.print("two");
        break;
      case 3:
      case 15:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          THREE(color);
        } else {
          scrollText("03:00 ", color);
        }
        ////Serial.print("three");
        break;
      case 4:
      case 16:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          FOUR(color);
        } else {
          scrollText("04:00 ", color);
        }
        ////Serial.print("four");
        break;
      case 5:
      case 17:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          FIVE(color);
        } else {
          scrollText("05:00 ", color);
        }
        ////Serial.print("five");
        break;
      case 6:
      case 18:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          SIX(color);
        } else {
          scrollText("06:00 ", color);
        }
        ////Serial.print("six");
        break;
      case 7:
      case 19:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          SEVEN(color);
        } else {
          scrollText("07:00 ", color);
        }
        ////Serial.print("seven");
        break;
      case 8:
      case 20:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          
          EIGHT(color);
        } else {
          scrollText("08:00 ", color);
        }
        ////Serial.print("eight");
        break;
      case 9:
      case 21:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          NINE(color);
        } else {
          scrollText("09:00 ", color);
        }
        ////Serial.print("nine");
        break;
      case 10:
      case 22:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          TEN(color);
        } else {
          scrollText("10:00 ", color);
        }
        //Serial.print("ten");
        break;
      case 11:
      case 23:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          ELEVEN(color);
        } else {
          scrollText("11:00 ", color);
        }
        //Serial.print("eleven", color);
        break;
      case 0:
      case 12:
        if (current.minute() > 0 && current.minute() < 5) {
          matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
          TWELVE(color);
        } else {
          scrollText("12:00 ", color);
        }
        //Serial.print("twelve");
        break;
    }
    //Serial.println("O'clock");
  } else if ((current.minute() > 4) && (current.minute() < 35)) {
    PAST(color);
    //Serial.print(" past ");
    switch (current.hour()) {
      case 1:
      case 13:
        ONE(color);
        //Serial.println("one");
        break;
      case 2:
      case 14:
        TWO(color);
        //Serial.println("two");
        break;
      case 3:
      case 15:
        THREE(color);
        //Serial.println("three");
        break;
      case 4:
      case 16:
        FOUR(color);
        //Serial.println("four");
        break;
      case 5:
      case 17:
        FIVE(color);
        //Serial.println("five");
        break;
      case 6:
      case 18:
        SIX(color);
        //Serial.println("six");
        break;
      case 7:
      case 19:
        SEVEN(color);
        //Serial.println("seven");
        break;
      case 8:
      case 20:
        EIGHT(color);
        //Serial.println("eight");
        break;
      case 9:
      case 21:
        NINE(color);
        //Serial.println("nine");
        break;
      case 10:
      case 22:
        TEN(color);
        //Serial.println("ten");
        break;
      case 11:
      case 23:
        ELEVEN(color);
        //Serial.println("eleven");
        break;
      case 0:
      case 12:
        TWELVE(color);
        //Serial.println("twelve");
        break;
    }
  } else {
    TO(color);
    //Serial.print(" to ");
    switch (current.hour()) {
      case 1:
      case 13:
        TWO(color);
        //Serial.println("two");
        break;
      case 2:
      case 14:
        THREE(color);
        //Serial.println("three");
        break;
      case 3:
      case 15:
        FOUR(color);
        //Serial.println("four");
        break;
      case 4:
      case 16:
        FIVE(color);
        //Serial.println("five");
        break;
      case 5:
      case 17:
        SIX(color);
        //Serial.println("six");
        break;
      case 6:
      case 18:
        SEVEN(color);
        //Serial.println("seven");
        break;
      case 7:
      case 19:
        EIGHT(color);
        //Serial.println("eight");
        break;
      case 8:
      case 20:
        NINE(color);
        //Serial.println("nine");
        break;
      case 9:
      case 21:
        TEN(color);
        //Serial.println("ten");
        break;
      case 10:
      case 22:
        ELEVEN(color);
        //Serial.println("eleven");
        break;
      case 11:
      case 23:
        TWELVE(color);
        //Serial.println("twelve");
        break;
      case 0:
      case 12:
        ONE(color);
        //Serial.println("one");
        break;
    }
  }
  delay(500);

}
