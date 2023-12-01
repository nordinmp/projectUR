void GaetTid ()
{
  int buttonPressedCount = 1;
  int buttonState = 0; 
  const int buttonPin = 3;
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

void StopUr() 
{
  int startTime;
  bool running = false;
  int elapsedTime = 0;
  int time;


if (running) 
{
  time = millis() - startTime + elapsedTime;

} else 
{
  time = elapsedTime;
}

  int minutes = time / 60000 | 0; 
  int seconds = (time % 60000) / 1000 | 0; 
  int milliseconds = (time % 1000) / 10 | 0;

  Serial.println(minutes);
  Serial.println(seconds);
  Serial.println(milliseconds);


}
void startStop() 
{

  int startTime;
  bool running = false;
  int elapsedTime = 0;
  int time;

  running = false;

  if (running) 
  {
   running = false;
   elapsedTime += millis() - startTime;

  } else 

  {
    running = true;
    startTime = millis();
  }
}

void reset() 
{
  int startTime;
  bool running = false;
  int elapsedTime = 0;
  int time;

    running = false;
    elapsedTime = 0;
  
}


void SwitchState (int count) 
{
  count = (count % 6) + 1;

  if (count == 1) 
  {
    GaetTid();
  }
  if (count == 2) 
  {
    Serial.print("Encoder value er 2");
  }
  if (count == 3) 
  {
    Serial.print("Encoder value er 3");
  }
  if (count == 4) 
  {
    Serial.print("Encoder value er 4");
  }
  if (count == 5) 
  {
    Serial.print("Encoder value er 5");
  }
  if (count == 6) 
  {
    Serial.print("Encoder value er 6");
  }
}