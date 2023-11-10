void GaetTid ()
{
int buttonPressedCount = 1;
    
    lcd.setRGB(colorR, colorG, colorB);

    lcd.print("Gæt tid");

    buttonState = digitalRead(buttonPin);
    Serial.print(random(1000,10000));
    int count = 0;
    int yourTime = 0;

        // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && ButtonPressedCount == 1) 
  {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    buttonPressedCount = buttonPressedCount + 1;
    count = millis();

  }
  else if(buttonState == HIGH && ButtonPressedCount == 2)
  {
    buttonPressedCount = buttonPressedCount + 1;
    yourTime = count;

  }

  else if(buttonState == HIGH && ButtonPressedCount == 3)
  {
    yourTime = count;
    Serial.print(yourTime);
    result = count - yourTime;
    Serial.print(result);
  }
}