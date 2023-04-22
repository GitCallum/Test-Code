#include <M5StickCPlus.h>

const double PWM_Hz = 50;
const uint8_t PWM_level = 16;
const uint16_t MIN_degree0 = 1700;
const uint16_t MAX_degree180 = 7000;

int pwm_cnt = 26;

#define SENSORPIN G0

void setup() {
  M5.begin();
  M5.Lcd.setRotation(1);  // M5stickCplus
  M5.Lcd.setTextSize(3);  // Font size

  pinMode(pwm_cnt, OUTPUT);
  ledcSetup((uint8_t)1, PWM_Hz, PWM_level);
  ledcAttachPin(pwm_cnt, 1);
  ledcWrite(1, MIN_degree0);

  pinMode(SENSORPIN, INPUT);
  digitalWrite(SENSORPIN, HIGH);
}

int sensorState = 0, lastState=0;

void loop() {

  sensorState = digitalRead(SENSORPIN);

  if(sensorState == LOW){
    ledcWrite(1, MIN_degree0);
  } 
  
  else{
    ledcWrite(1, MAX_degree180);
  } 
  M5.update();
}