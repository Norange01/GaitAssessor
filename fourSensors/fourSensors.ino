#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

#define BNO055_I2C_ADDR 0x28
#define I2C_SDA1 32
#define I2C_SCL1 33
#define I2C_SDA2 21
#define I2C_SCL2 22
#define FORCE1 25
#define FORCE2 26
TwoWire I2CBNO1 = TwoWire(0);
TwoWire I2CBNO2 = TwoWire(0);

// Initialize two BNO055 sensors
//Adafruit_BNO055 bno1 = Adafruit_BNO055(I2CBNO1,BNO055_I2C_ADDR);
//Adafruit_BNO055 bno2 = Adafruit_BNO055(57);

//I2CBNO2.begin(I2C_SDA2, I2C_SCL2, 100000);

void setup() {
  Serial.begin(921600);
  //I2CBNO1.begin(I2C_SDA1, I2C_SCL1, 100000);

  // Initialize BNO055 sensors
  //bno1.begin(0x76, &I2CBNO1); 
  //status2 = bno2.begin(0x76, &I2CBNO2); 
  //if (!status1) {
  //  Serial.println("Could not find valid BNO1 sensor, check wiring!");
  //  while (1);
  //}
  //if (!status2) {
  //  Serial.println("Could not find valid BNO2 sensor, check wiring!");
  //  while (1);
  //}


}

void loop() {
  // Read data from BNO055 sensor 1
  /*sensors_event_t event1;
  bno1.getEvent(&event1);

  Serial.print("BNO055 Sensor 1: ");
  Serial.print("Orientation X: ");
  Serial.print(event1.orientation.x);
  Serial.print(", Y: ");
  Serial.print(event1.orientation.y);
  Serial.print(", Z: ");
  Serial.print(event1.orientation.z);
  Serial.println();

  // Read data from BNO055 sensor 2
  //sensors_event_t event2;
  //bno2.getEvent(&event2);

  //Serial.print("BNO055 Sensor 2: ");
  //Serial.print("Orientation X: ");
  //Serial.print(event2.orientation.x);
  //Serial.print(", Y: ");
  //Serial.print(event2.orientation.y);
  //Serial.print(", Z: ");
  //Serial.print(event2.orientation.z);
  //Serial.println();*/

  // Read data from force sensor 1
  float force2_reading = abs(4095-analogRead(FORCE2));

  Serial.print("Force Sensor 2: ");
  Serial.println(force2_reading);

  // Read data from force sensor 2
  //float force2_reading = analogRead(FORCE2);

  //Serial.print("Force Sensor 2: ");
  //Serial.println(force2_reading);

  delay(1000);
}
