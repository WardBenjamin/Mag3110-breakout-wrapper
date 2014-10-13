#include "Mag3110.h"
#include <Wire.h>

//Mag3110 mag;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Setup"); 
}

void loop() 
{
  static Mag3110 mag;
  static Point2D points [100];
  Serial.println(mag.readx());
  delayMicroseconds(1000);
}
