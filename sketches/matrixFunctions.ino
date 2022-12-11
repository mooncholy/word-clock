void crossFade(RGB startColor, RGB endColor, int steps, int wait) {
  for(int i = 0; i <= steps; i++) {
    int newR = startColor.r + (endColor.r - startColor.r) * i / steps;
    int newG = startColor.g + (endColor.g - startColor.g) * i / steps;
    int newB = startColor.b + (endColor.b - startColor.b) * i / steps;

    matrix.fillScreen(matrix.Color(newR, newG, newB));
    matrix.show();
    delay(wait);
  }
}

void colorWipe(RGB color, uint8_t wait) {
  for(uint16_t row = 0; row < 8; row++) {
    for(uint16_t col = 0; col < 8; col++) {
      matrix.drawPixel(col, row, matrix.Color(color.r, color.g, color.b));
      matrix.show();
      delay(wait);
    }
  }
}

void scrollText(String textToDisplay, RGB color) {
  int x = matrix.width();
  int pixelIsInText = textToDisplay.length() * 7;

  matrix.setCursor(x, 0);
  matrix.print(textToDisplay);
  matrix.show();

  while(x > (matrix.width() - pixelIsInText)) {
    matrix.fillScreen(matrix.Color(color.r, color.g, color.b));
    matrix.setCursor(--x, 0);
    matrix.print(textToDisplay);
    matrix.show();
    delay(150);
  }
}
