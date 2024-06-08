/*
    Project name : Laser Module Control via Serial Communication
    Modified Date: 08-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-laser-sensor-module
*/

#define LASER_PIN 2   // Arduino pin connected to the laser module

void setup() 
{
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
  pinMode(LASER_PIN, OUTPUT); // Set LASER_PIN as output for laser module
}

void loop() 
{
  if (Serial.available() > 0) 
  { // Check if data is available to read
    char command = Serial.read(); // Read the incoming byte
    
    if (command == '1') {
      digitalWrite(LASER_PIN, HIGH); // Turn on the laser
      Serial.println("Laser turned ON");
    } else if (command == '0') {
      digitalWrite(LASER_PIN, LOW); // Turn off the laser
      Serial.println("Laser turned OFF");
    }
  }
}
