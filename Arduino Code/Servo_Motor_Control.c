#include <Servo.h>

const int potPin = A0;    // Potentiometer connected to analog pin A0
const int motorPin = 5;   // MOSFET gate connected to digital pin 5 (PWM)
const int servoPin = 9;   // Servo signal connected to digital pin 9

Servo myServo;

void setup() {
  // Initialize the servo motor
  myServo.attach(servoPin);
  // Set the initial position of the servo motor
  myServo.write(90); // Adjust this value as needed

  // Initialize the MOSFET pin
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Read the potentiometer value
  int potValue = analogRead(potPin);

  // Map the potentiometer value to a PWM value (0-255)
  int pwmValue = map(potValue, 0, 1023, 0, 255);

  // Write the PWM value to the motor pin to control speed
  analogWrite(motorPin, pwmValue);

  // Optional: Add a small delay to stabilize the loop
  delay(10);
}
