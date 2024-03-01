/*
   MCP42100 Dual 100K Digital Pot Demo
   Based on examples at https://wiki.dfrobot.com/Dual_Digital_Pot__100K__SKU__DFR0520

   Slowly adjusts pot wipers between min and max (0-255)
   to allow measuring the resistance from the wiper to
   one of the end terminals and to observe the operation of the device.

   Wiper setting is displayed on the serial monitor for confirmation.
   Arduino Uno SPI connections:
   Uno            MCP41100
   ------------------------
   D10           CS  (pin 1)
   D11 (MOSI)    SI  (pin 3)
   D13 (SCK)     SCK (pin 2)
*/

#include <SPI.h>

const byte csPin           = 10;      // MCP42100 chip select pin
const int  maxPositions    = 256;     // wiper can move from 0 to 255 = 256 positions
const long rAB             = 49800;   // 100k pot resistance between terminals A and B, 
                                      // mais pour ajuster au multimètre, je mets 92500
const byte rWiper          = 125;     // 125 ohms pot wiper resistance
const byte pot0            = 0x11;    // pot0 addr // B 0001 0001
const byte pot0Shutdown    = 0x21;    // pot0 shutdown // B 0010 0001

void setPotWiper(int addr, int pos) {
  pos = constrain(pos, 0, 255);            // limit wiper setting to range of 0 to 255
  digitalWrite(csPin, LOW);                // select chip
  SPI.transfer(addr);                      // configure target pot with wiper position
  SPI.transfer(pos);
  digitalWrite(csPin, HIGH);               // de-select chip

  // print pot resistance between wiper and B terminal
  long resistanceWB = ((rAB * pos) / maxPositions ) + rWiper;
  Serial.print("Wiper position: ");
  Serial.print(pos);
  Serial.print(" Resistance wiper to B terminal: ");
  Serial.print(resistanceWB);
  Serial.println(" ohms");
}

void setup() {
  Serial.begin(9600);
  Serial.println("MCP41100 Demo");
  
  digitalWrite(csPin, HIGH);        // chip select default to de-selected
  pinMode(csPin, OUTPUT);           // configure chip select as output
  SPI.begin();
}

void loop() {
  // move pot1 wiper manually to specific positions
  Serial.println("Pot 0 Control ");

  setPotWiper(pot0, 0);                    // minimum resistance
  delay(3000);
  setPotWiper(pot0, 64);                   // 25% resistance
  delay(3000);
  setPotWiper(pot0, 128);                  // 50% resistance
  delay(3000);
  setPotWiper(pot0, 192);                  // 75% resistance
  delay(3000);
  setPotWiper(pot0, 255);                  // 100% resistance
  delay(3000);

  // move pot0 wiper from min to max in increments of 1 position
  Serial.println("Pot 0 Control ");
  for (int i = 0; i < 256; i++) {
    setPotWiper(pot0, i);
    delay(1000);
  }
  // move pot0 wiper from max to min in decrements of 1 position
  for (int i = 256; i > 0; i--) {
    setPotWiper(pot0, i);
    delay(1000);
  }
}


