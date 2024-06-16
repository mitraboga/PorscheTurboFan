#include <PID_v1.h>

// Define pins
const int pressureSensorPin = A0; // Analog input pin for pressure sensor
const int actuatorPin = 9;        // PWM output pin for actuator

// Define variables
double setpoint = 0;      // Desired pressure value
double input = 0;         // Current pressure value from sensor
double output = 0;        // Output value to actuator

// PID parameters
double Kp = 2.0, Ki = 5.0, Kd = 1.0;

// Create PID controller
PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the actuator pin as an output
  pinMode(actuatorPin, OUTPUT);

  // Initialize the pressure sensor pin as an input
  pinMode(pressureSensorPin, INPUT);

  // Set the PID controller parameters
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(0, 255); // PWM output range
}

void loop() {
  // Read the current pressure value from the sensor
  input = analogRead(pressureSensorPin);

  // Map the analog input (0-1023) to the actual pressure range (0-100 psi for example)
  input = map(input, 0, 1023, 0, 100);

  // Set the desired pressure setpoint (this could be set dynamically based on other inputs)
  setpoint = 50; // Example: target pressure is 50 psi

  // Compute the PID output
  myPID.Compute();

  // Write the output to the actuator
  analogWrite(actuatorPin, output);

  // Print the values for debugging
  Serial.print("Input: ");
  Serial.print(input);
  Serial.print(" Setpoint: ");
  Serial.print(setpoint);
  Serial.print(" Output: ");
  Serial.println(output);

  // Wait for a short interval before next loop
  delay(100);
}