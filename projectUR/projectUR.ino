#include "functions.h"
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

#include <Encoder.h>

Encoder myEnc(5, 4);



void setup() 
{
  // put your setup code here, to run once:
      // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  delay(1000);
  Serial.begin(9600);

  const int buttonPin = 4;

  pinMode(buttonPin, INPUT);


}

int encoderValue  = 0;

void loop() 
{
  // lav encoder om til godt tal
  int encoderValue = myEnc.read();
  int encoderValueCount = (encoderValue / 4 * (-1));

  SwitchState(encoderValueCount);

  // put your main code here, to run repeatedly:
  //GaetTid();
}
