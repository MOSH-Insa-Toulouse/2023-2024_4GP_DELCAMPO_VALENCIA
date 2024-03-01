/*     ———————————————————
*     |  Arduino Experimentation Kit Example Code             |
*     |  CIRC-10 .: Temperature :. (TMP36 Temperature Sensor) |
*     ———————————————————
*  
*  A simple program to output the current temperature to the IDE’s debug window
*
*  For more details on this circuit: http://tinyurl.com/c89tvd
*/

//TMP36 Pin Variables
int Pin = 0;  //the analog pin the TMP36's Vout (sense) pin is connected to
                         //the resolution is 10 mV / degree centigrade
                         //(500 mV offset) to make negative temperatures an option

/*
* setup() – this function runs once when you turn your Arduino on
* We initialize the serial connection with the computer
*/
void setup() {
  Serial.begin(9600);
    //Start the serial connection with the copmuter
                              //to view the result open the serial monitor
                              //last button beneath the file bar (looks like a box with an antenae)
}

void loop()  // run over and over again
{
  float Tension = getVoltage(Pin);  //getting the voltage reading from the temperature sensor
           //converting from 10 mv per degree wit 500 mV offset
                                                   //to degrees ((volatge – 500mV) times 100)
  Serial.println(Tension);                     //printing the result
  delay(100);                                     //waiting a second
}

/*
* getVoltage() – returns the voltage on the analog input defined by
* pin
*/
float getVoltage(int pin) {
  return (analogRead(pin) * 0.00488281);  //converting from a 0 to 1023 digital range
                                          // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}
