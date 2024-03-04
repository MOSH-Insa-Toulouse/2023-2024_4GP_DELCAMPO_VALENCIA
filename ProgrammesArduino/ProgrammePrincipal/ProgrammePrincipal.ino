/*Ça c'est le programme principal*/

/*Pour le potentiomètre variable câbler:
  ------------------------
   D10           CS  (pin 1)
   D11 (MOSI)    SI  (pin 3)
   D13 (SCK)     SCK (pin 2)
*/

#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include <Adafruit_SSD1306.h>

#define rxPinBT 10 //Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPinBT 11 //Broche 10 en tant que RX, à raccorder sur TX du HC-05

#define ampliPin 0 //Broche A0 qui récupère Vout de l'amplificateur
#define flexSensorPin 1 //Broche A1 qui récupère Vout du flex sensor

#define baudrate 9600

#define encoder0PinCLK  2  //CLK Output A Do not use other pin for clock as we are using interrupt
#define encoder0PinDT 4  //DT Output B
#define Switch 5 // Switch connection if available

#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C 

Servo ServoBanc; //définition classe du servomoteur du banc
SoftwareSerial mySerial(rxPinBT ,txPinBT); //Définition du software serial
Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED); //Définition classe écran OLED


volatile unsigned int encoder0Pos = 0;

int pos=0, pos_max =150, pos_min=20;
// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 39000.0;  // resistor used to create a voltage divider
const float flatResistance = 31000.0; // resistance when flat
const float bendResistance = 100000.0;  // resistance at 90 deg

const byte csPin           = 10;      // MCP42100 chip select pin
const int  maxPositions    = 256;     // wiper can move from 0 to 255 = 256 positions
const long rAB             = 49800;   // 100k pot resistance between terminals A and B, 
                                      // mais pour ajuster au multimètre, je mets 92500
const byte rWiper          = 125;     // 125 ohms pot wiper resistance
const byte pot0            = 0x11;    // pot0 addr // B 0001 0001
const byte pot0Shutdown    = 0x21;  

void setup() {
  pinMode(rxPinBT,INPUT);//setup BT
  pinMode(txPinBT,OUTPUT);  
  mySerial.begin(baudrate);
  Serial.begin(baudrate);

  pinMode(flexSensorPin, INPUT);//setup flexsensor
  ServoBanc.attach(9); //setup servo

  pinMode(encoder0PinCLK, INPUT); 
  digitalWrite(encoder0PinCLK, HIGH);       // turn on pullup resistor

  pinMode(encoder0PinDT, INPUT); 
  digitalWrite(encoder0PinDT, HIGH);       // turn on pullup resistor

  attachInterrupt(0, doEncoder, RISING); // encoder pin on interrupt 0 - pin2

  digitalWrite(csPin, HIGH);        // chip select default to de-selected
  pinMode(csPin, OUTPUT);           // configure chip select as output
  SPI.begin();

  // Initialisation de l'écran OLED
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
    while(1);                               // Arrêt du programme (boucle infinie) si échec d'initialisation
}

void loopBT(){
  while (mySerial.available()) {
		Serial.print((float)mySerial.read(),"V");
	}
}

void doEncoder() {
  if (digitalRead(encoder0PinDT)==HIGH) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
}

void mesureFlex() {
  // Read the ADC, and calculate voltage and resistance from it
  int ADCflex = analogRead(flexSensorPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  Serial.println("Resistance: " + String(Rflex) + " ohms");

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();
}

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

/*
* getVoltage() – returns the voltage on the analog input defined by
* pin
*/
float getVoltage(int pin) {
  return (analogRead(pin) * 0.00488281);  //converting from a 0 to 1023 digital range
                                          // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}


void loop()  // run over and over again
{
  float Tension = getVoltage(ampliPin);  //getting the voltage reading from the temperature sensor
  Serial.println(Tension);                     //printing the result
  delay(100);                                     //waiting a 100 milliseconds
}
