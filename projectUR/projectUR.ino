#include "state.h"

#include "functions.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include "DS1307.h"


rgb_lcd lcd;

State currentState = UR;




const int buttonPin = 3;
int buttonState = 0; 


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
  pinMode(encoderButtonPin, INPUT);


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




void loop() {
 // Read encoder value
 encoderValue = myEnc.read();
 int encoderValueCount = (encoderValue / 4 * (-1));

  buttonState = digitalRead(buttonPin);

  Serial.println(encoderValue);
  Serial.println(buttonState);
  Serial.println(currentState);

  if (interruptActive == true) {
      updateStopwatch();
  }

 // Print the name of the state that corresponds to the current encoder value
 if (encoderValueCount == 1) {
  lcd.setCursor(0, 0);
  lcd.print("Gæt Tiden           ");
  if (buttonState == 1) {
    clickSound();
    currentState = GAET_TIDEN;
  }
 } else if (encoderValueCount == 2) {
  lcd.setCursor(0, 0);
  lcd.print("Stopur              ");
  if (buttonState == 1) {
    currentState = STOPUR;
  }
 } else if (encoderValueCount == 3) {
  lcd.setCursor(0, 0);
  lcd.print("Ur                  ");
  if (buttonState == 1) {
    currentState = UR;
  }
 } else if (encoderValueCount == 4) {
  lcd.setCursor(0, 0);
  lcd.print("Kog Æg              ");
  if (buttonState == 1) {
    currentState = KOG_AEG;
  }
 } 

  // Perform action based on current state
  switch (currentState) {
    case GAET_TIDEN:
      GaetTid();
      break;
    case STOPUR:
      // Set the interrupt to active
      interruptActive = true;
      break;
    case UR:
      printTime();
      break;
    case KOG_AEG:
      kogAeg();
      break;
  }
}

