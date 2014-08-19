/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int ledPin = 13;
int color;
int pwmLed = 5;
int soundPin = 9;
int sound;
//int rLed = 9;
//int gLed = 10;
//int bLed = 11;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT); 
  //pinMode(rLed, OUTPUT);
  //pinMode(gLed, OUTPUT); 
  //pinMode(bLed, OUTPUT);
  pinMode(pwmLed,OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(soundPin, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  // turn the ledPin on
  //digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  //delay(sensorValue)x;          
  // turn the ledPin off:        
  //digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  //delay(sensorValue);
  //digitalWrite(ledPin, HIGH);
  analogWrite(pwmLed, (255-color));
 // delay(sensorValue);
  color =map(sensorValue, 15, 100, 0, 255); 
  color=constrain(color, 0, 255);
  sound=map(color, 0, 255, 10, 500);
  
  //analogWrite(rLed, color);
  tone(soundPin, sound, 10);
  
  //Serial.println(color); 
  
  Serial.println(sensorValue); 

 
}
