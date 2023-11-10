void GaetTid ()
{
  int buttonPressedCount = 1;
  int buttonState = 0; 
  const int buttonPin = 4;
  int timeGuess = random(1000,10000);

  unsigned long startTime = 0;

  int count = 0;
  int yourTime = 0;
  int result = 0;

  pinMode(buttonPin, INPUT);

  while(true) // We start a loop here to continuously check the button state
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
      count = millis() - startTime; // Calculate the elapsed time
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
      yourTime = count;
      Serial.print("Your time is: ");
      Serial.println(yourTime); // This line will print the value of yourTime
      result = timeGuess - yourTime;
      Serial.print("Result: ");
      Serial.println(result); // This line will print the result
      delay(50);
      buttonPressedCount = 1;
      buttonState = 0;
    }

    delay(100); // Debounce delay
  }
}
