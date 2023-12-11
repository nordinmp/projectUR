#include "state.h"
#include "DS1307.h"
#include "rgb_lcd.h"
#include <Encoder.h>


extern rgb_lcd lcd;


Encoder myEnc(5, 4);
Encoder EncBotton(9, 8);

int encoderButtonPin = 8;
int encoderValue = 0;

void GaetTid ()
{
  int buttonPressedCount = 1;
  extern int buttonState; 
  extern const int buttonPin;
  extern int encoderValueCount;

  extern State currentState;

  int timeGuess = random(1000,10000);

  unsigned long startTime = 0;

  int count = 0;
  int yourTime = 0;
  int result = 0;

  bool playGame = true;



  while(playGame == true) // We start a loop here to continuously check the button state
  {
    buttonState = digitalRead(buttonPin); // Update button state

    if (buttonState == HIGH && buttonPressedCount == 1) 
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tryk når tiden");
      lcd.setCursor(0, 1);
      lcd.print("er gået");
      delay(50);
      buttonPressedCount++;
      buttonState = 0;
    }
    else if (buttonState == HIGH && buttonPressedCount == 2) 
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Gæt tiden: ");
      lcd.setCursor(0, 1);
      lcd.print(timeGuess);
      delay(50);
      buttonPressedCount++;
      buttonState = 0;
    }
    else if(buttonState == HIGH && buttonPressedCount == 3)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      startTime = millis(); // Store the start time
      yourTime = count;
      lcd.print("Tæller...");
      buttonPressedCount++;
      buttonState = 0;
    }
    else if(buttonState == HIGH && buttonPressedCount == 4)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tryk igen for at");
      lcd.setCursor(0, 1);
      lcd.print("se resultater");
      delay(50);
      buttonPressedCount++;
      buttonState = 0;
    }
    else if(buttonState == HIGH && buttonPressedCount == 5)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      count = millis() - startTime; // Calculate the elapsed time
      yourTime = count;
      lcd.print("Din tid: ");
      lcd.print(yourTime); // This line will print the value of yourTime
      result = timeGuess - yourTime;
      lcd.setCursor(0, 1);
      lcd.print("Result: ");
      lcd.print(result); // This line will print the result
      delay(50);
      buttonPressedCount++;
      buttonState = 0;
    }
    else if(buttonState == HIGH && buttonPressedCount == 6)
    {
      buttonPressedCount = 1;
      buttonState = 0;
      playGame = false;
      lcd.clear();
    }

    delay(100); // Debounce delay
  } 

  currentState = NONE;
}

extern const int buttonPin;
 
// Define the state of the stopwatch
bool running = false;

// Define the start time and elapsed time
unsigned long startTid;
unsigned long elapsedTime = 0;

// Define a flag to control when the interrupt should be active
bool interruptActive = false;

void startStop() 
{
 if (running) 
 {
  // If running, stop the stopwatch
  running = false;
  elapsedTime = millis() - startTid;
 } 
 else 
 {
  // If not running, start the stopwatch
  running = true;
  startTid = millis() - elapsedTime;
 }
}


void updateStopwatch()
{
 unsigned long time;

 if (running) {
 // If running, calculate elapsed time
  time = millis() - startTid;
 } else {
 // If not running, use the stored elapsed time
  time = elapsedTime;
 }

 // Convert time to minutes, seconds, and milliseconds
 int minutes = time / 60000;
 int seconds = (time % 60000) / 1000;
 int milliseconds = (time % 1000) / 10;

 // Print the time to the Serial Monitor
 lcd.setCursor(0, 0);
 lcd.print("Stopur Time: ");
 lcd.setCursor(0, 1);
 lcd.print(minutes);
 lcd.print("m ");
 lcd.print(seconds);
 lcd.print("s ");
 lcd.print(milliseconds);
 lcd.print("ms");
}


DS1307 clock;

void printTime() {
    clock.getTime();
    lcd.setCursor(0, 0);
    lcd.print("Ur: ");
    lcd.print(clock.hour, DEC);
    lcd.print(":");
    lcd.print(clock.minute, DEC);
    lcd.print(":");
    lcd.print(clock.second, DEC);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print(clock.month, DEC);
    lcd.print("/");
    lcd.print(clock.dayOfMonth, DEC);
    lcd.print("/");
    lcd.print(clock.year + 2000, DEC);
    lcd.print(" ");
    switch (clock.dayOfWeek) { // Friendly printout the weekday
        case MON:
            lcd.print("MON");
            break;
        case TUE:
            lcd.print("TUE");
            break;
        case WED:
            lcd.print("WED");
            break;
        case THU:
            lcd.print("THU");
            break;
        case FRI:
            lcd.print("FRI");
            break;
        case SAT:
            lcd.print("SAT");
            break;
        case SUN:
            lcd.print("SUN");
            break;
    }
    lcd.print(" ");
}


int encoderValueCount;

void kogAeg()
{
  encoderValue = myEnc.read();
  encoderValue = 0;
  int encoderValueCount = (encoderValue / 4 * (-1));

  bool chooseEgg = true;

  extern const int buttonPin;

  int buttonState = digitalRead(buttonPin);

  long startTime;
  long time = 0;
  bool startCountdown = false;
  while (chooseEgg) 
  {

    encoderValueCount = (encoderValueCount % 3) + 1;


    Serial.println(encoderValueCount);
  

    lcd.setCursor(0, 0);
    lcd.print("Vælg æg type");

      if (encoderValueCount == 1)
      {
        lcd.setCursor(0, 1);
        lcd.print("Blødkogt    ");

        if (buttonState == HIGH)
        {
          time = 300000;
          startTime = millis();
          startCountdown = true;
          chooseEgg = false;
          buttonState = 0;
        }
      }
      if (encoderValueCount == 2)
      {
        lcd.setCursor(0, 1);
        lcd.print("Smilende     ");

        if (buttonState == HIGH)
        {
          time = 420000;
          startTime = millis();
          startCountdown = true;
          chooseEgg = false;
          buttonState = 0;
        }
      }
      if (encoderValueCount == 3)
      {
        lcd.setCursor(0, 1);
        lcd.print("Hårdkogt    ");

        if (buttonState == HIGH)
        {
          time = 540000;
          startTime = millis();
          startCountdown = true;
          chooseEgg = false;
          buttonState = 0;
        }
      }
  }
  

  while (startCountdown)
  {
    long currentTime = millis();
    long elapsedTime = currentTime - startTime;

    if (elapsedTime < time)
    {
      time -= elapsedTime;
      startTime = currentTime;
    }
    else
    {
      time = 0;
      startCountdown = false;
    }

    int minutes = time / 60000;
    int seconds = (time % 60000) / 1000;
    int milliseconds = (time % 1000) / 10;

    lcd.setCursor(0, 0);
    lcd.print("Æg er klar om:");
    lcd.setCursor(0, 1);
    lcd.print(minutes);
    lcd.print(":");
    lcd.print(seconds);
    lcd.print(":");
    lcd.print(milliseconds);
    lcd.print("           ");
    delay(10);
  }
}

void clickSound() 
{
  digitalWrite(2,HIGH);
  delay(10);
  digitalWrite(2,LOW);

}