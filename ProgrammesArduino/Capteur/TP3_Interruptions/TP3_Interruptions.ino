// --- Programme Arduino --- 
// Bas&eacute; sur le programme de X. HINAULT  
// Programme Ecrit le : 13/2/2011.

//  See GNU General Public License for more details.
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see &lt;<a href="http://www.gnu.org/licenses/&gt" class="_blanktarget">http://www.gnu.org/licenses/&gt</a>;.

// ////////////////////  PRESENTATION DU PROGRAMME //////////////////// 

// -------- Que fait ce programme ? ---------
 /* Ce programme compte les impulsions en provenance d&#039;un bouton 
en utilisant l&#039;interruption externe n&deg;0 sur la broche 2 de la carte Arduino. 
Le r&eacute;sultat est affich&eacute; dans le Terminal S&eacute;rie du logiciel Arduino.  */ 

// --- Fonctionnalit&eacute;s utilis&eacute;es --- 

// Utilise la connexion s&eacute;rie vers le PC 
// Utilise l&#039;interruption externe 0 (broche 2)
// Utilise un bouton poussoir,


// -------- Circuit &agrave; r&eacute;aliser --------- 

// La connexion s&eacute;rie vers le PC utilise les broches 0 et 1 (via le c&acirc;ble USB) 
// Broche 2 : La sortie du bouton poussoir 

// --- D&eacute;claration des variables globales ---

volatile int comptageImpulsion=0; // variable accessible dans la routine interruption externe 0

void setup()   { // debut de la fonction setup()

// ------- Initialisation fonctionnalit&eacute;s utilis&eacute;es -------  
Serial.begin(115200); // initialise connexion s&eacute;rie &agrave; 115200 bauds
// IMPORTANT : r&eacute;gler le terminal c&ocirc;t&eacute; PC avec la m&ecirc;me valeur de transmission 

attachInterrupt(0, gestionINT0, RISING); // attache l&#039;interruption externe n&deg;0 &agrave; la fonction gestionINT0()
// mode d&eacute;clenchement possibles = LOW, CHANGE, RISING, FALLING

} // fin de la fonction setup()
// ********************************************************************************

void loop(){ // debut de la fonction loop()
// tout se passe dans la fonction de gestion de l&#039;interruption externe

} // fin de la fonction loop() - le programme recommence au d&eacute;but de la fonction loop sans fin
// ********************************************************************************


// ////////////////////////// FONCTIONS DE GESTION DES INTERRUPTIONS //////////////////// 

// ------------------- fonction de gestion l&#039;interruption externe n&deg;0 (broche 2) ----------------
// cette fonction est appel&eacute;e &agrave; chaque fois que l&#039;interruption a lieu selon le mode configur&eacute; (LOW, CHANGE, RISING, FALLING)

void gestionINT0() {// la fonction appel&eacute;e par l&#039;interruption externe n&deg;0

comptageImpulsion=comptageImpulsion+1; // Incr&eacute;mente la variable de comptage
// ATTENTION : delay() et millis() non dispo ici - donn&eacute;es s&eacute;rie perdues

//---- affiche le nombre d&#039;impulsions sur le port s&eacute;rie
Serial.print("Nombre impulsions = "); 
Serial.println(comptageImpulsion); 
}

