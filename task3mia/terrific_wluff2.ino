#include <Wire.h>



// C++ code

#define LED 11
int x=0;
void setup()
{
  pinMode(LED, OUTPUT);
  Wire.begin(10);
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes)
{
	x=Wire.read();
}
void loop()
{
 if (x == '0') {
    analogWrite(LED, 0);
    Serial.begin(9600);
    Serial.print("no message");
    
  }
 if (x == '1') {
    analogWrite(LED, 127);
    Serial.begin(9600);
    Serial.print("Vector focused");
    
  }
 if (x == '2') {
    analogWrite(LED, 191);
    Serial.begin(9600);
    Serial.print("Vector distracted");
    
  }
 if (x == '3') {
    analogWrite(LED, 255);
    Serial.begin(9600);
    Serial.print("Glitch");
    
  }  
}