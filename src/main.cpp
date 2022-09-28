// Luca Quacquarelli
// 000838997
// 2022-09-26
// Mohawk College - COMP-10184 
// Statement of authorship: I Luca Quacqarelli, 000838997 certify that this material is my original work.
//No other person's work has been used without due acknowledgement. 

#include <Arduino.h> 


const int led = D4;// We will use the internal LED
const int iButton = D5;// this pin is our push button
const int readValue = A0;// this pin is our potentiometer

// A variable to store the last state of the button 
int lastButtonState = HIGH;
bool LEDOn = true; // on or off switch



void setup() {
  // configure the USB serial monitor 
  Serial.begin(115200); 

  pinMode(led, OUTPUT); // Set the LED Pin as an output
  pinMode(iButton, INPUT_PULLUP); // Set the Tilt Switch as an input

  analogWriteRange(1023); //set default PWM range
}// end setup()


void loop() {
  
  int buttonState = digitalRead(iButton);  // Take a reading
  
  // ... and write it to the LED output 
  int potentiometerValue = analogRead(readValue);

  // checking the current and last state of the button
  if (buttonState == LOW && lastButtonState == HIGH) { // button has been released

    // Checking if the led is on or off 
    if(LEDOn) { 
        LEDOn = false; //Off 
    }
    else { 
      LEDOn = true; // On 
    }

    delay(1);
  }
  // The last state of the button now equals the current state of the button 
  lastButtonState = buttonState;

  // Depending on if the lead is on or off  
  if (LEDOn) {
    // Turn the led back to the potentiometer value 
    digitalWrite(led, potentiometerValue); 
  }
  else {
    // Turn the LED completely off 
    digitalWrite(led, HIGH); 
  }
  delay(1);
}// end loop()
 
