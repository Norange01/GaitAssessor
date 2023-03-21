#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

#define patientFootAngle 10 //in degrees

#define FORCE1 25
#define FORCE2 26

//foot
#define SDA_1 19
#define SCL_1 23
//leg
#define SDA_2 21
#define SCL_2 22

TwoWire I2Cone = TwoWire(0);
TwoWire I2Ctwo = TwoWire(1);
#define BNO055_SAMPLERATE_DELAY_MS (100)
#define sensor1 26

Adafruit_BNO055 bno1 = Adafruit_BNO055(55, 0x28, &I2Cone);
Adafruit_BNO055 bno2 = Adafruit_BNO055(55, 0x28, &I2Ctwo);

void setup() {
  //Wire.begin();
  Serial.begin(921600);
  I2Cone.begin(SDA_1, SCL_1, 100000);
  I2Ctwo.begin(SDA_2, SCL_2, 100000);
  
  Serial.println("\nI2C Scanner");

  if(!bno1.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055_1 detected ... Check your wiring or I2C ADDR!");
    //while(1);
  }

  if(!bno2.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055_2 detected ... Check your wiring or I2C ADDR!");
    //while(1);
  }
  displaySensorDetails();

}

//function that checks if any I2C device is connected (it will show multiple devices 
//at different addresses if they are recognized and connected correctly)
void checkI2C() {
  byte error, address;
  int nDevices;
  //Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      //Serial.print("I2C device found at address 0x");
      //if (address<16) {
        //Serial.print("0");
      //}
      //Serial.println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      Serial.print("Unknown error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  //else {
    //Serial.println("done\n");
  //}
}

void displaySensorDetails(void)
{
  sensor_t sensor;
  bno1.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" xxx");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" xxx");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" xxx");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(100);

  bno2.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" xxx");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" xxx");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" xxx");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void loop() {
  

  // Read data from force sensor 1
  float force1_reading = abs(4095-analogRead(FORCE1));

  Serial.print("Foot Front Force (/4095): ");
  Serial.println(force1_reading);

  // Read data from force sensor 2
  float force2_reading = abs(4095-analogRead(FORCE2));

  Serial.print("Heal Force (/4095): ");
  Serial.println(force2_reading);

  //checkI2C();

  imu::Vector<3> accel_value1 = bno1.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  imu::Vector<3> accel_value2 = bno2.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  imu::Vector<3> euler1 = bno1.getVector(Adafruit_BNO055::VECTOR_EULER);
  imu::Vector<3> euler2 = bno2.getVector(Adafruit_BNO055::VECTOR_EULER);

  //Print IMU Data from BNO's
  sensors_event_t event1; 
  bno1.getEvent(&event1);
  sensors_event_t event2; 
  bno2.getEvent(&event2);
  
  Serial.println("Ankle Angle:");
  if(abs(event2.orientation.z)<90){Serial.print(abs(180-event2.orientation.y+event1.orientation.y)+patientFootAngle);}
  else{Serial.print(abs(event2.orientation.y+event1.orientation.y)+patientFootAngle);}
  Serial.print("\n---------------------\n");
  
  /*
  Serial.print("X: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY: ");
  if(abs(event.orientation.z)<90){Serial.print(180-event.orientation.y, 4);}
  else{Serial.print(event.orientation.y, 4);}
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.println("");
  Serial.print("\n---------------------\n");*/

  delay(500);          
}
