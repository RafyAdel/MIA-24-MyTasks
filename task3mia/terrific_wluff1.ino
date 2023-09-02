#include <Wire.h>

// C++ code

#define PB1 2 //push button 1
#define PB2 3 //push button 2
int x = 0;
void setup()
{
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  attachInterrupt(digitalPinToInterrupt(PB1), go, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PB2), go, CHANGE);
  Wire.begin();
}
void go()
{   
	Wire.beginTransmission(10); // transmit to device #10
    Wire.write(x);
    Wire.endTransmission();
}
void loop()
{   
	
     if ((digitalRead(8)== LOW)&&(digitalRead(7)==LOW))
       x=0;
     if ((digitalRead(8)== HIGH)&&(digitalRead(7)==LOW))
       x=1;
     if ((digitalRead(8)== LOW)&&(digitalRead(7)==HIGH))
       x=2;
     if ((digitalRead(8)== HIGH)&&(digitalRead(7)==HIGH))
       x=3;
}