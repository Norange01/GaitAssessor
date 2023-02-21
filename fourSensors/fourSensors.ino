#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>


#define FORCE1 25
#define FORCE2 26

void setup() {
  Serial.begin(921600);



}

void loop() {
  

  // Read data from force sensor 1
  float force1_reading = abs(4095-analogRead(FORCE1));

  Serial.print("Force Sensor 1: ");
  Serial.println(force1_reading);

  // Read data from force sensor 2
  float force2_reading = abs(4095-analogRead(FORCE2));

  Serial.print("Force Sensor 2: ");
  Serial.println(force2_reading);

  delay(100);
}
