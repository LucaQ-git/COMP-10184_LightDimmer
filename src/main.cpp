// Mohawk College - COMP-10184 
// 
// Pulse Width Modulation - Test Program 
// 
#include <Arduino.h> 

int readValue = 0;
int iButton;

int state = 0;

int buttonOld = 1;


void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(iButton,INPUT);
  pinMode(D4, OUTPUT); 
 
  // set default PWM range 
  analogWriteRange(1023); 
} 

void loop() { 
 
   // read digitized value from the D1 Mini's A/D convertor 
  readValue = analogRead(A0); 

  // turn the LED ON 
  analogWrite(D4, readValue); 
   
 
  // read the push button input... 
  iButton = digitalRead(D5); 

  //iButton=digitalRead(buttonPin);
  if(state == 0) {
    if (state == 1) {
      digitalWrite(D4,HIGH);
      state = 1;
    }
    else{
      digitalWrite(D4, LOW);
      state = 0;
    }
  }
  buttonOld=iButton;
  delay(100);

  

  /*
  if (digitalRead(iButton) == readValue){
    if (buttonflag == 0) {             
      buttonflag = 1;                  
      digitalWrite(D4, HIGH);     
      }                           
    else {                        
      buttonflag = 0;                  
      digitalWrite(D4, LOW);      
    }
    delay(1);
  }  */ 
  // wait 1ms 
 // delay(1); 
 
  // turn the LED OFF 
  //digitalWrite(D4, iVal); 
  // wait 9ms 
  //delay(9); 
 
}





/*
static boolean oldSwitchState = digitalRead(iButton);
  boolean newSwitchState = digitalRead(readValue);
  
  if (newSwitchState != oldSwitchState) {
    // Switch has changed state.  Remember the new state
    oldSwitchState = newSwitchState;
    digitalWrite(readValue, HIGH);
    delay(100);  // Pulse length
    digitalWrite(readValue, LOW);
  }
 int i; 
   
  for ( i=0; i<1024; ++i) { 
    // set the PWM pulse width 
    analogWrite(D4, i); 
 
    // wait 1ms to add DRAMA! 
    delay(1); 
  } */

/*
void loop() { 
  // turn the LED ON 
  digitalWrite(D4, LOW); 
  // wait 1ms 
  delay(1); 
 
  // turn the LED OFF 
  digitalWrite(D4, HIGH); 
  // wait 9ms 
  delay(9); 
} */

/*
void loop() { 
  // turn the LED ON 
  digitalWrite(D4, LOW); 
  // wait 10ms 
  delay(10); 
 
  // turn the LED OFF 
  digitalWrite(D4, HIGH); 
  // wait 1990ms 
  delay(1990); 
} */
 
 /*
void loop() { 
  // turn the LED ON 
  digitalWrite(D4, LOW); 
  // wait 1s 
  delay(1000); 
 
  // turn the LED OFF 
  digitalWrite(D4, HIGH); 
  // wait 1s 
  delay(1000); 
} */

 