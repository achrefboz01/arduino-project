#include <PS4Controller.h>
#include <Arduino.h>

const uint8_t IN11 = 27;
const uint8_t IN12 = 14;
const uint8_t IN13=  12;
const uint8_t IN14 = 13;
const uint8_t IN21 = 26;
const uint8_t IN22 = 25;
const uint8_t IN23 = 33;
const uint8_t IN24 = 32;
void setup() {
  Serial.begin(115200);
  PS4.begin("94:54:c5:b0:a3:34");  // Remplacez par l'adresse MAC de votre manette
  pinMode(IN11, OUTPUT);
  pinMode(IN12, OUTPUT);
  pinMode(IN13, OUTPUT);
  pinMode(IN14, OUTPUT);
  pinMode(IN21, OUTPUT);
  pinMode(IN22, OUTPUT);
  pinMode(IN23, OUTPUT);
  pinMode(IN24, OUTPUT);

}

void stopp() {
  digitalWrite(IN11, 0);
  digitalWrite(IN12, LOW);
  digitalWrite(IN13, LOW);
  digitalWrite(IN14, 0);
  digitalWrite(IN21, 0);
  digitalWrite(IN22, LOW);
  digitalWrite(IN23, LOW);
  digitalWrite(IN24, 0);
}

void forward() {
    digitalWrite(IN11, 0);
  digitalWrite(IN12, 1);
  digitalWrite(IN13, LOW);
  digitalWrite(IN14, 1);
  digitalWrite(IN21, 0);
  digitalWrite(IN22, 1);
  digitalWrite(IN23, LOW);
  digitalWrite(IN24, 1);
}

void backward() {
   digitalWrite(IN11, 1);
  digitalWrite(IN12, LOW);
  digitalWrite(IN13, 1);
  digitalWrite(IN14, 0);
  digitalWrite(IN21, 1);
  digitalWrite(IN22, LOW);
  digitalWrite(IN23, 1);
  digitalWrite(IN24, 0);
}

void gauche() {

  digitalWrite(IN11, 1);
  digitalWrite(IN12, LOW);
  digitalWrite(IN13, 1);
  digitalWrite(IN14, 0);
  digitalWrite(IN21, 0);
  digitalWrite(IN22, LOW);
  digitalWrite(IN23, LOW);
  digitalWrite(IN24, 0);
}

void droit() {
  digitalWrite(IN11, 1);
  digitalWrite(IN12, LOW);
  digitalWrite(IN13, 1);
  digitalWrite(IN14, 0);
  digitalWrite(IN21, 0);
  digitalWrite(IN22, LOW);
  digitalWrite(IN23, LOW);
  digitalWrite(IN24, 0);
}

void loop() {
  if (PS4.isConnected()) {

    if (PS4.R1()) {
      backward();
      Serial.println("Recule");
    } else if (PS4.Right()) {
      droit();
      Serial.println("Droite");
   
    } else if (PS4.L1()) {
      forward();
      Serial.println("UP");
    } else if (PS4.Left()) {
      gauche();
      Serial.println("Gauche");
} else {
      stopp();
      Serial.println("Stop");
    }
  }
}
