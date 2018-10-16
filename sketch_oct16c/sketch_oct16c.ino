/*
  Morse

  Un simple programme qui permets de faire un petit manipulateur morse.

  Il permet de voir l'utilisation :
    - d'une entrée  : D2
    - d'une sortie  : D3
    - d'un if


  Pierre HUGUET
  pierre.huguet.projets@gmail.com
  03/09/2014
*/

#include  <Wire.h>
#include <I2C_LCD.h>
#include <LiquidCrystal.h>
uint8_t I2C_LCD_ADDRESS = 0x51;

// Declaration des moyens Mnemoniques
#define Bouton  2
#define Buzzer  4
#define LCD  6


void setup() 
{
  // Initialisation des entrée et des sorties
  pinMode(Bouton, INPUT);
  pinMode(LCD, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

// Boucle principale du programme
void loop() 
{
  if (digitalRead(Bouton) == true)
  {
    digitalWrite(Buzzer, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    digitalWrite(Buzzer, LOW);   // turn the LED on (HIGH is the voltage level)
  }
}
