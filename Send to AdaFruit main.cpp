#include <M5StickCPlus.h>
#include <AdafruitIO_WiFi.h>

#define SENSORPIN G0

AdafruitIO_WiFi io("Andre_Gablogian", "aio_NrZN46ZYXlNWilN2Q8MudHtMHmto", "UoE-Device", "Wmc7df4y");
AdafruitIO_Feed *SunData = io.feed("SunFeed");

void setup() {
  // put your setup code here, to run once:
  M5.begin();

  io.connect();
  delay(1000);

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    M5.Lcd.print(".");
    delay(500);
  }

  M5.Lcd.setRotation(1);  // M5stickCplus
  M5.Lcd.setTextSize(3);  // Font size

  pinMode(SENSORPIN, INPUT);
  digitalWrite(SENSORPIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.println("Chicken out");
  SunData->save(0);
  while(digitalRead(SENSORPIN) == HIGH){}


  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.println("Chicken in");
  SunData->save(1);

  while(digitalRead(SENSORPIN) == LOW){}
}