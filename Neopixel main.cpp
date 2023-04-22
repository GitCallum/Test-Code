#include <Adafruit_NeoPixel.h>
#include <M5StickCPlus.h>

#define NEOPIN G26
#define NUM_PIXELS  8

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, NEOPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  NeoPixel.begin();

  NeoPixel.setBrightness(100);
}

void loop() {

  for (int pixel = 0; pixel < NUM_PIXELS; pixel++){
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(228, 10, 14));
    NeoPixel.show();
    delay(500);
  }

  while (digitalRead(M5_BUTTON_HOME) == HIGH) {}

    for (int pixel = 0; pixel < NUM_PIXELS; pixel++){
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(240, 110, 30));
      NeoPixel.show();
      delay(500);
    }

    while (digitalRead(M5_BUTTON_HOME) == HIGH) {}
}