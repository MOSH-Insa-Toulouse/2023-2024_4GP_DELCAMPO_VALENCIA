/*
  Fichier :       afficherTexteSsd1306.ino
  Description :   Affiche du texte de test, sur un écran OLED i2c de 128x64 pixels,
                  fonctionnant avec un contrôleur SSD1306
  Auteur :        Jérôme TOMSKI (https://passionelectronique.fr/)
  Créé le :       26.07.2021
*/

#include <Adafruit_SSD1306.h>

#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);

void setup() {

  // Initialisation de l'écran OLED
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
    while(1);                               // Arrêt du programme (boucle infinie) si échec d'initialisation

  // *************************************************************************
  // Affichage de 3 écrans successifs, avec zoom sur police x1, puis x2, et x3
  // *************************************************************************
  for(byte tailleDeCaractere=1; tailleDeCaractere <=3; tailleDeCaractere++) {
    boolean bCouleurInverse = false;
    ecranOLED.clearDisplay();                                   // Effaçage de l'intégralité du buffer
    ecranOLED.setTextSize(tailleDeCaractere);                   // Taille des caractères (1:1, puis 2:1, puis 3:1)
    ecranOLED.setCursor(0, 0);                                  // Déplacement du curseur en position (0,0), c'est à dire dans l'angle supérieur gauche

    // ***********************************************************************
    // Affichage de 8 lignes à couleurs alternées, dans chaque écran successif
    // ***********************************************************************
    for(byte numeroDeLigne=1; numeroDeLigne<=8; numeroDeLigne++) {
      if(bCouleurInverse)
        ecranOLED.setTextColor(SSD1306_BLACK, SSD1306_WHITE);   // Couleur du texte, et couleur du fond
      else
        ecranOLED.setTextColor(SSD1306_WHITE);                  // Affichage du texte en "blanc" (avec la couleur principale, en fait, car l'écran monochrome peut être coloré)
      ecranOLED.print("Hello bobi! ");
      ecranOLED.println(numeroDeLigne);
      bCouleurInverse = !bCouleurInverse;
    }
    ecranOLED.display();                            // Transfert le buffer à l'écran
    delay(2000);
  }
}

void loop() {
  // Aucun code dans cette partie, car tout se passe dans la fonction setup !
}
