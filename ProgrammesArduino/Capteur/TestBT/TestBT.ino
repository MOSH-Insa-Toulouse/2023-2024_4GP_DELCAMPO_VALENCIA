#include <SoftwareSerial.h>
#define rxPin 9 // Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 8 // Broche 10 en tant que TX, à raccorder sur RX du HC-05

byte serialRX;
volatile byte RX=0;
SoftwareSerial mySerial(rxPin, txPin);
void setup()
{
 // define pin modes for tx, rx pins:
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 mySerial.begin(9600);
 Serial.begin(9600);
}
void loop(){


if(mySerial.available()){
serialRX=mySerial.read();
 Serial.println(serialRX);
 App(serialRX);}}

void App(int serialRX){
switch (serialRX) {
            case(1): // si arduino reçois le chiffre 1 alors envoi de la position du potentiomètre
              Serial.println(1); 
              break;
            case(2): // si arduino reçois le chiffre 2 alors envoi de la tension en sortie de l'amplificateur sur 256 bits (1octet)
              mySerial.println(5);
              break;
            case(3): // si arduino reçois le chiffre 3 alors incrément de la position du potentiomètre
              
              Serial.println("xd");
             break; 
            case(4): // si arduino reçois le chiffre 4 alors décrément de la position du potentiomètre
            
              Serial.println("lol");
              break;
              }
}


