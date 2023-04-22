#include <M5StickCPlus.h>
#include <AdafruitIO_WiFi.h>
#include "comands.h"



//#include "PrivateVariables.h"

AdafruitIO_WiFi io("Andre_Gablogian", "aio_NrZN46ZYXlNWilN2Q8MudHtMHmto", "UoE-Device", "Snj7VrGm");
AdafruitIO_Feed *counter = io.feed("SunFeed");

int count = 0;

//============================================
// SETUP
void setup() {
  // init M5Stick
  M5.begin();

  pinMode(CState, OUTPUT);

  M5.Lcd.println("Connecting to AdafruitIO");

  io.connect();
  delay(1000);

  // set up a message handler for the count feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  counter->onMessage(handleMessage);

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    M5.Lcd.print(".");
    delay(500);

  }

  // Because Adafruit IO doesn't support the MQTT retain flag, we can use the
  // get() function to ask IO to resend the last value for this feed to just
  // this MQTT client after the io client is connected.
  counter->get();

  // we are connected
  M5.Lcd.println();
  M5.Lcd.println(io.statusText());

  // set text size, rotation
  M5.Lcd.setTextSize(2);
  M5.Lcd.setRotation(1);
}

//============================================
// LOOP
void loop() {
  io.run();


}

// this function is called whenever a 'counter' message
// is received from Adafruit IO. it was attached to
// the counter feed in the setup() function above.
