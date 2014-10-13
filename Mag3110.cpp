/* 
 MAGG3110 Breakout Wrapper
 
 by: Benjamin Ward, bwardbsa at gmail dot com
   WardBenjamin (on Github dot com)
   FTC Team 4592
   
   date: 10/12/2014
   licence: rootbeerware, if you use this code and happen to meet me, you 
         can buy me a root beer. Also, I would appreciate an email!
   
   This class provides a wrapper for the Mag3110 Breakout from Sparkfun
   Electronics, providing functions to read the 16-bit x, y, and z values.
   Currently, there is no wrapper to use the INT1 pin, or for polling for
   new data.
   
   Credit to Aaron Weiss (aaron at sparkfun dot com) for my use of the 
   example code that he has provided. (original date: 9/6/11).
*/

#include <Arduino.h>
#include <Wire.h>

#define MAG_ADDR  0x0E // 7-bit address for the MAG3110, doesn't change

#include "MagFunctions.h"

Mag3110::Mag3110() 
{
  Serial.println("Constructor");
  this->setup();
}

void Mag3110::setup() 
{
  Serial.println("Setup");
  Wire.begin(); // Join I2C bus (address optional for master)
  this->config();
}

void Mag3110::config(void) 
{
  Wire.beginTransmission(MAG_ADDR); // Transmit to device 0x0E
  Wire.write(0x11);              // Cntrl register2
  Wire.write(0x80);              // Send 0x80, enable auto resets
  Wire.endTransmission();       // Stop transmitting
  
  delay(15);
  
  Wire.beginTransmission(MAG_ADDR); // Transmit to device 0x0E
  Wire.write(0x10);              // Cntrl register1
  Wire.write(1);                 // Send 0x01, active mode
  Wire.endTransmission();       // Stop transmitting
}

int Mag3110::readx(void) 
{
  int xl, xh;  // Define the MSB and LSB
  
  Wire.beginTransmission(MAG_ADDR); // Transmit to device 0x0E
  Wire.write(0x01);              // x MSB reg
  Wire.endTransmission();       // Stop transmitting
 
  delayMicroseconds(2); // Needs at least 1.3us free time between start and stop
  
  Wire.requestFrom(MAG_ADDR, 1); // Request 1 byte
  while(Wire.available())    // Slave may send less than requested
  { 
    xh = Wire.read(); // Receive the byte
  }
  
  delayMicroseconds(2); // Needs at least 1.3us free time between start and stop
  
  Wire.beginTransmission(MAG_ADDR); // Transmit to device 0x0E
  Wire.write(0x02);              // x LSB reg
  Wire.endTransmission();       // Stop transmitting
 
  delayMicroseconds(2); // Needs at least 1.3us free time between start and stop
  
  Wire.requestFrom(MAG_ADDR, 1); // Request 1 byte
  while(Wire.available())    // Slave may send less than requested
  { 
    xl = Wire.read(); // Receive the byte
  }
  
  int xout = (xl|(xh << 8)); // Concatenate the MSB and LSB
  return xout;
}

int Mag3110::ready(void)
{
  int yl, yh;  // Define the MSB and LSB
  
  Wire.beginTransmission(MAG_ADDR); // Transmit to device 0x0E
  Wire.write(0x03);              // y MSB reg
  Wire.endTransmission();       // Stop transmitting
 
  delayMicroseconds(2); // Needs at least 1.3us free time between start and stop
  
  Wire.requestFrom(MAG_ADDR, 1); // Request 1 byte
  while(Wire.available())    // Slave may send less than requested
  { 
    yh = Wire.read(); // Receive the byte
  }
  
  delayMicroseconds(2); // Needs at least 1.3us free time between start and stop
  
  Wire.beginTransmission(MAG_ADDR); // Transmit to device 0x0E
  Wire.write(0x04);              // y LSB reg
  Wire.endTransmission();       // Stop transmitting
 
  delayMicroseconds(2); // Needs at least 1.3us free time between start and stop
  
  Wire.requestFrom(MAG_ADDR, 1); // Request 1 byte
  while(Wire.available())    // Slave may send less than requested
  { 
    yl = Wire.read(); // Receive the byte
  }
  
  int yout = (yl|(yh << 8)); // Concatenate the MSB and LSB
  return yout;
}

int Mag3110::readz(void)
{
  int zl, zh;  // Define the MSB and LSB
  
  Wire.beginTransmission(MAG_ADDR); // Transmit to device 0x0E
  Wire.write(0x05);              // z MSB reg
  Wire.endTransmission();       // Stop transmitting
 
  delayMicroseconds(2); // Needs at least 1.3us free time between start and stop
  
  Wire.requestFrom(MAG_ADDR, 1); // Request 1 byte
  while(Wire.available())    // Slave may send less than requested
  { 
    zh = Wire.read(); // Receive the byte
  }
  
  delayMicroseconds(2); // Needs at least 1.3us free time between start and stop
  
  Wire.beginTransmission(MAG_ADDR); // Transmit to device 0x0E
  Wire.write(0x06);              // z LSB reg
  Wire.endTransmission();       // Stop transmitting
 
  delayMicroseconds(2); // Needs at least 1.3us free time between start and stop
  
  Wire.requestFrom(MAG_ADDR, 1); // Request 1 byte
  while(Wire.available())    // Slave may send less than requested
  { 
    zl = Wire.read(); // Receive the byte
  }
  
  int zout = (zl|(zh << 8)); // Concatenate the MSB and LSB
  return zout;
}
