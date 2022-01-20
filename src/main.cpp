/*
  Titre      : exercice est de contrôler l'intensité d'une LED avec le potentiomètre
  Auteur     : Yvan Tankeu
  Date       : 20/01/2022
  Description: Le but de cet exercice est de contrôler l'intensité d'une LED avec le potentiomètre
               utilisé en salle de classe.  Pour ce faire, nous allons, étrangement,
               utilisé la fonction analogWrite sur une broche numérique!!!  En fais, c'est un
               overload (OO)
  Version    : 0.0.1
*/

#include <Arduino.h>

const int POTENTIOMETRE = A1;                   // Potentiomètre connecté sur broche analogue A1
const int LED = 2;                              // Led connecté sur la broche digital 2
const int VAL_MIN_LU_ECRIT_BROCHE_ANALOGUE = 0; // Val min qu'on peut lire/écricre sur broche analogue 2
const int VAL_MAX_LU_BROCHE_ANALOGUE = 1023;    // Val  max lu sur broche analogue 2
const int VAL_MAX_ECRIT_BROCHE_ANALOGUE = 255;  // Val max lu sur broche analogue 2

int valeurTensionLuPotentiometre = 0;

void setup()
{

  Serial.begin(9600); // Debit de communication par seconde depuis le MS

  // Ajuste le mode des broches
  pinMode(POTENTIOMETRE, INPUT); // Paramétrage broche du potentiomètre en mode d'entrée/écoute/lecture
  pinMode(LED, OUTPUT);          // Paramétrage broche de la LED mode d'entrée/écoute/lecture
}

void loop()
{
  // put your main code here, to run repeatedly:

  valeurTensionLuPotentiometre = analogRead(POTENTIOMETRE); // Lecture de la valeur du potentiomètre

      /** grace à la fonction map on pourra ré-étalonner la valeur entre 0 et 1023
          sur une fourchette entre 0 et 255
      * @brief mapper un nombre d’une plage de 1 à 1024 à une plage de 1 à 255,
      *
      * @param valeurTensionLuPotentiometre variable dont on souhaite convertir la plage.
      * @param VAL_MIN_LU_ECRIT_BROCHE_ANALOGUE valeur minimale d’origine de la plage de la variable.
      * @param VAL_MAX_LU_BROCHE_ANALOGUE valeur maximale d’origine de la plage de la variable.
      * @param VAL_MIN_LU_ECRIT_BROCHE_ANALOGUE maximale de la nouvelle plage de la variable.
      */
      valeurTensionLuPotentiometre = map(valeurTensionLuPotentiometre, VAL_MIN_LU_ECRIT_BROCHE_ANALOGUE,
                                         VAL_MAX_LU_BROCHE_ANALOGUE, VAL_MIN_LU_ECRIT_BROCHE_ANALOGUE, VAL_MAX_ECRIT_BROCHE_ANALOGUE);
  analogWrite(LED, valeurTensionLuPotentiometre);
}
