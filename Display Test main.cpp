#include <M5StickCPlus.h>

int DisStart;

int TimeStart;

RTC_TimeTypeDef RTC_TimeStruct;
RTC_DateTypeDef RTC_DateStruct;

void SetupTime(){
    RTC_TimeTypeDef TimeStruct;
    TimeStruct.Hours = 11;
    TimeStruct.Minutes = 11;
    TimeStruct.Seconds = 11;
    M5.Rtc.SetTime(&TimeStruct);

    RTC_DateTypeDef DateStruct;
    DateStruct.Month = 4;
    DateStruct.Date = 28;
    DateStruct.Year = 2023;
    M5.Rtc.SetData(&DateStruct);
}
void DisTime(){
    if (millis() - TimeStart  > 1000){
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setTextSize(2);
        M5.Rtc.GetTime(&RTC_TimeStruct);
        M5.Rtc.GetData(&RTC_DateStruct);
        M5.Lcd.setCursor(20, 45, 4);
        M5.Lcd.printf("%02d:%02d:%02d\n", RTC_TimeStruct.Hours, RTC_TimeStruct.Minutes, RTC_TimeStruct.Seconds);
        M5.Lcd.setCursor(42, 10, 2);
        M5.Lcd.setTextSize(2);
        M5.Lcd.printf("%04d-%02d-%02d\n", RTC_DateStruct.Year, RTC_DateStruct.Month, RTC_DateStruct.Date);
        TimeStart = millis();
    }
}

void SunRiseSet(){
    if (millis() - TimeStart  > 1000){
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(70, 10, 1);
    M5.Lcd.print("Sun Rise");
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(0, 55, 4);
    M5.Lcd.print("------------------------------");
    M5.Lcd.setCursor(55, 35, 4);
    M5.Lcd.print("5:56:13 AM");
    M5.Lcd.setCursor(75, 75, 1);
    M5.Lcd.setTextSize(2);
    M5.Lcd.println("Sun Set");
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(55, 100, 4);
    M5.Lcd.print("6:06:13 PM");
   


    TimeStart = millis();
    }
}
void LengthOfDay(){
    if (millis() - TimeStart  > 1000){
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(60, 30, 1);
    M5.Lcd.println("Day Length");
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(70, 55, 4);
    M5.Lcd.println("12:22:22");

    TimeStart = millis();
    }
}

void setup() {
  M5.begin();
  TimeStart = millis();
  DisStart = millis();
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(BLACK);
  // put your setup code here, to run once:
}

int DisNum = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(DisNum == 0){
    DisTime();
  }

   else if(DisNum == 2 && (millis() - TimeStart) > 250) {
    LengthOfDay();
  }
  else if(DisNum == 1 && (millis() - TimeStart) > 250){
    SunRiseSet();
  }

  if(digitalRead(M5_BUTTON_HOME) == LOW && (millis()-DisStart)>250){
  
      if(DisNum == 2){
      DisNum = 0;
      }
      else if(DisNum == 0){
        DisNum = 1;
        //beensent = 0;
      }
      else if(DisNum == 1){
        DisNum = 2;
      }

      DisStart = millis();
  }
}