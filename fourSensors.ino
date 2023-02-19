#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <HX711.h>

#define I2C_SDA1 32
#define I2C_SCL1 33
#define I2C_SDA2 21
#define I2C_SCL2 22
#define FORCE1 23
#define FORCE2 25
TwoWire I2CBNO1 = TwoWire(0);
TwoWire I2CBNO2 = TwoWire(0);

// Initialize two BNO055 sensors
Adafruit_BNO055 bno1 = Adafruit_BNO055(55);
Adafruit_BNO055 bno2 = Adafruit_BNO055(57);
I2CBNO1.begin(I2C_SDA1, I2C_SCL1, 100000);
I2CBNO2.begin(I2C_SDA2, I2C_SCL2, 100000);

// Initialize two force sensors
HX711 force1;
HX711 force2;

void setup() {
  Serial.begin(9600);

  // Initialize BNO055 sensors
  status1 = bno1.begin(0x76, &I2CBNO1); 
  status2 = bno2.begin(0x76, &I2CBNO2); 
  if (!status1) {
    Serial.println("Could not find valid BNO1 sensor, check wiring!");
    while (1);
  }
  if (!status2) {
    Serial.println("Could not find valid BNO2 sensor, check wiring!");
    while (1);
  }

  // Initialize force sensors
  force1.begin(5, 4);
  force2.begin(7, 6);

  force1.set_scale(2000);
  force2.set_scale(2000);

  force1.tare();
  force2.tare();
}

void loop() {
  // Read data from BNO055 sensor 1
  sensors_event_t event1;
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
  sensors_event_t event2;
  bno2.getEvent(&event2);

  Serial.print("BNO055 Sensor 2: ");
  Serial.print("Orientation X: ");
  Serial.print(event2.orientation.x);
  Serial.print(", Y: ");
  Serial.print(event2.orientation.y);
  Serial.print(", Z: ");
  Serial.print(event2.orientation.z);
  Serial.println();

  // Read data from force sensor 1
  float force1_reading = analogRead(FORCE1);

  Serial.print("Force Sensor 1: ");
  Serial.println(force1_reading);

  // Read data from force sensor 2
  float force2_reading = analogRead(FORCE2);

  Serial.print("Force Sensor 2: ");
  Serial.println(force2_reading);

  delay(1000);
}
