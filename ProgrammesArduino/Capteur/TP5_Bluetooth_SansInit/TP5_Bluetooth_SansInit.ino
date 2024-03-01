/*
Programme de reception Bluetooth via le logiciel MIT APP Inventor 
- connectez deux leds sur les sorties digitales 13 et 12
- connecter le module bluetooth sur les broches 0 et 1 , puis l'alim GND 5V (une fois le programme uploadé)

Attention, avant d'uploader ce programme, veillez à débrancher le module bluetooth
car celui-ci utilise les broches 0 et 1 utilisées aussi pour uploader
un programme dans arduino

MATERIEL - MODULE BLUETOOTH V2: 
Pin 1 - VCC => 3.3V Arduino 
Pin 2 - TX => RX Arduino 
Pin 3 - RX => TX Arduino 
Pin 10 - Ground => Ground Arduino

*/

/* ENTETE DECLARATIVE */
//#define DEBUG

const int ledPin_Red = 12; // la led sera fixée à la broche 13
const int ledPin_Green = 13; // la led sera fixée à la broche 12
byte serialRX; // variable de reception de donnée via RX
byte serialTX; // variable de transmission de données via TX
volatile byte RX = 0; 
boolean lastButtonState = LOW;
boolean buttonState;
int impulsion = 0; 
const int speed_serial = 9600;      // communication Bluetooth 
// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;


// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup()
{
  Serial.begin(speed_serial); // initialisation de la connexion série (avec le module bluetooth)
  setupBlueToothConnection(); // démarrage liason série bluetooth cf fonction en bas

  pinMode(ledPin_Red, OUTPUT); // fixe la pin "ledpin" en sortie
  pinMode(ledPin_Green, OUTPUT); // fixe la pin "ledpin" en sortie
  
  //Déclaration du bouton poussoir
  pinMode(pushButton, INPUT);
}

void loop() {

  if (RX){
        RX=0;  
        Serial.println(serialRX); 
        switch (serialRX) {
        case 1: // si arduino reçois le chiffre 1 alors
          digitalWrite(ledPin_Red, LOW); // allume sur la broche "ledpin"
          digitalWrite(ledPin_Green, HIGH); // allume sur la broche "ledpin"
          break;
        case 2: // si arduino reçois le chiffre 2 alors
          digitalWrite(ledPin_Red, HIGH); // allume sur la broche "ledpin"
          digitalWrite(ledPin_Green, LOW); // allume sur la broche "ledpin"
          break;
        case 3: // si arduino reçois le chiffre 3 alors "clignote"
          RX = 1;
          digitalWrite(ledPin_Red, LOW); // assure l'extinction de la LED VERTE
          digitalWrite(ledPin_Green, HIGH);
          delay(200);
          digitalWrite(ledPin_Green, LOW);
          delay(200);
        }
  }
  
  
  ///////////////////////////////////////
  // read the input pin: Mettre un pull-up
  boolean reading  = digitalRead(pushButton);
  //Serial.println(reading);
  // print out the state of the button:

  if (reading != lastButtonState){
     lastDebounceTime=millis();
  }
    if ((millis()-lastDebounceTime) > debounceDelay){
      if ((reading == HIGH)&& (reading != buttonState)) { 

          #ifdef DEBUG
                   Serial.print("reading:");Serial.print(reading);
                   Serial.print("|buttonState:");Serial.print(buttonState);
                   Serial.print("|buttonState_Last:");Serial.print(buttonState);
                   Serial.print("|impulsion:");
          #endif

            impulsion = impulsion + 1; 
            Serial.println(impulsion);
       }
       buttonState = reading;
     }//fin du millis
   
lastButtonState = reading;
  ///////////////////////////////////////

}//fin du loop

//La fonction serialEvent est appelé après chaque boucle loop si un caractère est arrivé sur le port
void serialEvent(){ // si arduino reçoit quelquechose sur l'entrée RX
  serialRX = Serial.read(); // stocker la valeur reçue dans la variable SerialA 
  RX = 1; //met la valeur RX à 1
}

void setupBlueToothConnection() // fonction de configuration du module bluetooth
{
/*
  Serial.begin(speed_serial); //vitesse de bluetooth
                              //initialisation de la connexion série (avec le module bluetooth)

  //  Serial.print("\r\n+STBD=115200\r\n"); // fixe la vitesse du bluetooth
  Serial.print("\r\n+STBD=9600\r\n"); // fixe la vitesse du bluetooth
  Serial.print("\r\n+STWMOD=0\r\n"); //bluetooth en mode esclave
  Serial.print("\r\n+STNA=Arduino"); //nom de l'appareil
  Serial.print("\r\n+STPIN=0000\r\n");//code pin "0000"
  Serial.print("\r\n+STOAUT=1\r\n"); // Permit Paired device to connect me
  Serial.print("\r\n+STAUTO=0\r\n"); // Auto-connection should be forbidden here
  delay(2000); // This delay is required.
  Serial.print("\r\n+INQ=1\r\n"); //make the slave bluetooth inquirable 
  delay(2000); // This delay is required.
  Serial.flush();
*/
}
