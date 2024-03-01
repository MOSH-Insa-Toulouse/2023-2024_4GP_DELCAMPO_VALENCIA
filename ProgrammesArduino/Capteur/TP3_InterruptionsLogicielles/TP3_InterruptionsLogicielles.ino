
#include <MsTimer2.h> 
// inclusion de la librairie Timer2
const int LED=2; 
// declaration constante de broche 
void setup(){ 
pinMode(LED, OUTPUT); 
//met la broche en sortie 
// initialisation interruption Timer 2
MsTimer2::set(1000, InterruptTimer2); 
// période 1000ms 
MsTimer2::start(); 
// active Timer2 
} // fin de la fonction setup()

void loop(){ // debut de la fonction loop
}

//*************** Autres Fonctions du programme *************
void InterruptTimer2() { 
// debut de la fonction d'interruption Timer2
digitalWrite(LED, HIGH); delayMicroseconds(10000); 
// la fonction delayMicroseconds ne bloque pas les interruptions
digitalWrite (LED, LOW);

}
