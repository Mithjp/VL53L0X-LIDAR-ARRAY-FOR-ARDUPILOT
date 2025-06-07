#include <Wire.h>
#include <VL53L0X.h>

//#define XSHUT_pin6 A7  //not required for address change
//#define XSHUT_pin5 A6
#define XSHUT_pin4 A3
#define XSHUT_pin3 A2
#define XSHUT_pin2 A1
#define XSHUT_pin1 A0

//ADDRESS_DEFAULT 0b0101001 or 41
//#define Sensor1_newAddress 41 not required address change
#define Sensor2_newAddress 42
#define Sensor3_newAddress 43
#define Sensor4_newAddress 44
#define Sensor5_newAddress 45
#define Sensor6_newAddress 46

VL53L0X Sensor1;
VL53L0X Sensor2;
VL53L0X Sensor3;
VL53L0X Sensor4;
//VL53L0X Sensor5;
//VL53L0X Sensor6;

void setup()
{ /*WARNING*/
  //Shutdown pins of VL53L0X ACTIVE-LOW-ONLY NO TOLERANT TO 5V will fry them
  pinMode(XSHUT_pin1, OUTPUT);
  pinMode(XSHUT_pin2, OUTPUT);
  pinMode(XSHUT_pin3, OUTPUT);
  pinMode(XSHUT_pin4, OUTPUT);
//  pinMode(XSHUT_pin5, OUTPUT);
//  pinMode(XSHUT_pin6, OUTPUT);
  
  Serial.begin(115200);
  
  Wire.begin();
  //Change address of sensor and power up next one
 // Sensor6.setAddress(Sensor6_newAddress);//For power-up procedure t-boot max 1.2ms "Datasheet: 2.9 Power sequence"
 
 // pinMode(XSHUT_pin5, INPUT);
 // delay(10); 
 // Sensor5.setAddress(Sensor5_newAddress);
 
  pinMode(XSHUT_pin4, INPUT);
  delay(10);
  Sensor4.setAddress(Sensor4_newAddress);

  pinMode(XSHUT_pin3, INPUT);
  delay(10);
  Sensor3.setAddress(Sensor3_newAddress);
  
  pinMode(XSHUT_pin2, INPUT);
  delay(10);
  Sensor2.setAddress(Sensor2_newAddress);
  
  pinMode(XSHUT_pin1, INPUT);
  delay(10);
  //ADDRESS_DEFAULT 0b0101001 or 41
 Serial.println("Starting I2C scan...");
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.print(" (");
      Serial.print(address);
      Serial.println(")");
    }
  }
  Serial.println("Scan done.");
}



void loop()
{

    
}