#include "functions.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include "DS1307.h"
#include <Encoder.h>


rgb_lcd lcd;


Encoder myEnc(5, 4);


const int buttonPin = 3;
int buttonState = 0; 
int encoderValue  = 1;
int encoderValueCount;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;


void setup() 
{
  // put your setup code here, to run once:
      // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  delay(1000);
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), startStop, FALLING);

  Serial.begin(9600);
  clock.begin();
  clock.fillByYMD(2023, 12, 4); //Jan 19,2013
  clock.fillByHMS(12, 00, 00); //15:28 30"
  clock.fillDayOfWeek(MON);//Saturday
  clock.setTime();//write time to the RTC chip

      // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  lcd.setRGB(colorR, colorG, colorB);


  delay(1000);
}


void loop() 
{
  // lav encoder om til godt tal
  int encoderValue = myEnc.read();
  int encoderValueCount = (encoderValue / 4 * (-1));

  SwitchState(encoderValueCount);

  if (interruptActive == true) {
      updateStopwatch();
  }
  //StopUr();
  // put your main code here, to run repeatedly:
  //GaetTid();
}
