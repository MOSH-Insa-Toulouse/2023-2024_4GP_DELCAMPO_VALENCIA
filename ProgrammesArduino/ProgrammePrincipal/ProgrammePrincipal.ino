//Ça c'est le programme principal
#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>

int PinAmpli = 0;  //the analog pin the TMP36's Vout (sense) pin is connected to
                         //the resolution is 10 mV / degree centigrade
                         //(500 mV offset) to make negative temperatures an option


void setup() {
  Serial.begin(9600);
    //
}

void loop()  // run over and over again
{
  float Tension = getVoltage(PinAmpli);  //getting the voltage reading from the temperature sensor
  Serial.println(Tension);                     //printing the result
  delay(100);                                     //waiting a 100 milliseconds
}

/*
* getVoltage() – returns the voltage on the analog input defined by
* pin
*/
float getVoltage(int pin) {
  return (analogRead(pin) * 0.00488281);  //converting from a 0 to 1023 digital range
                                          // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}
