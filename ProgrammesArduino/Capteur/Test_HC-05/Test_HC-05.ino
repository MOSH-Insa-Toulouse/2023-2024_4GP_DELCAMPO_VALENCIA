#include <SoftwareSerial.h>
#define rxPin 9 //Broche 11 en tant que RX, � raccorder sur TX du HC-05
#define txPin 8 //Broche 10 en tant que RX, � raccorder sur TX du HC-05
#define baudrate 9600
SoftwareSerial mySerial(rxPin ,txPin); //D�finition du software serial

void setup(){
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
    
  mySerial.begin(baudrate);
  Serial.begin(baudrate);
}

void loop(){
Serial.print(mySerial.read());
mySerial.println("Holi");}

