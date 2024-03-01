#include <Servo.h>
const int flexPin = A0;      // Pin connected to voltage divider output
Servo myservo;
int pos=0, pos_max =150, pos_min=20;
// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 39000.0;  // resistor used to create a voltage divider
const float flatResistance = 31000.0; // resistance when flat
const float bendResistance = 100000.0;  // resistance at 90 deg

void setup() {
  Serial.begin(9600);
  pinMode(flexPin, INPUT);
  myservo.attach(9);
}

void mesure() {
  // Read the ADC, and calculate voltage and resistance from it
  int ADCflex = analogRead(flexPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  Serial.println("Resistance: " + String(Rflex) + " ohms");

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();
}
void loop() {
  for(pos=pos_min;pos<=pos_max;pos+=1)
  {
    myservo.write(pos);
    mesure();
    delay(20);
  }


  for(pos=pos_max;pos>=pos_min;pos-=1)
  {
    myservo.write(pos);
    mesure();
    delay(20);
  }
  delay(500);
}
