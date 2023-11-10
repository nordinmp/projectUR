#incude "functions.h"
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int buttonPin = 2;
int buttonState = 0;

void setup() 
{
  // put your setup code here, to run once:
      // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    delay(1000);

      pinMode(buttonPin, INPUT);

}

void loop() 
{
  // put your main code here, to run repeatedly:

}
