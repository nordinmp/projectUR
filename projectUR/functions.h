void SwitchState (int count); // må ikke slettes det er en blank med vilje


void GaetTid ()
{
  int buttonPressedCount = 1;
  extern int buttonState; 
  extern const int buttonPin;
  extern int encoderValueCount;

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
      Serial.print("Tryk når du tror tiden er gået");
      Serial.print("Tiden du skal gætte er ");
      Serial.print(timeGuess);
      delay(50);
      buttonPressedCount++;
      buttonState = 0;
    }
    else if(buttonState == HIGH && buttonPressedCount == 2)
    {
      startTime = millis(); // Store the start time
      yourTime = count;
      Serial.print("Tæller...");
      buttonPressedCount++;
      buttonState = 0;
    }
    else if(buttonState == HIGH && buttonPressedCount == 3)
    {
      Serial.print("Tryk igen for at se resultater");
      delay(50);
      buttonPressedCount++;
      buttonState = 0;
    }
    else if(buttonState == HIGH && buttonPressedCount == 4)
    {
      count = millis() - startTime; // Calculate the elapsed time
      yourTime = count;
      Serial.print("Your time is: ");
      Serial.println(yourTime); // This line will print the value of yourTime
      result = timeGuess - yourTime;
      Serial.print("Result: ");
      Serial.println(result); // This line will print the result
      delay(50);
      buttonPressedCount = 1;
      buttonState = 0;

      playGame = false;
    }

    delay(100); // Debounce delay
  } 
  SwitchState (encoderValueCount);
}

void SwitchState (int count) 
{
  count = (count % 6) + 1;

  extern const int buttonPin;
  extern int buttonState; 

  buttonState = digitalRead(buttonPin);

  if (count == 1 && buttonState == HIGH) 
  {
    GaetTid();
  }
  if (count == 2 && buttonState == HIGH) 
  {
    Serial.println("Encoder value er 2");
  }
  if (count == 3 && buttonState == HIGH) 
  {
    Serial.println("Encoder value er 3");
  }
  if (count == 4 && buttonState == HIGH) 
  {
    Serial.println("Encoder value er 4");
  }
  if (count == 5 && buttonState == HIGH) 
  {
    Serial.println("Encoder value er 5");
  }
  if (count == 6 && buttonState == HIGH) 
  {
    Serial.println("Encoder value er 6");
  }
}