#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <string.h>
#define bo 1
#define bo1 2
#define bo2 3
#define bo3 4
#define bo4 5
#define bo5 6
#define bo6 7
#define bo7 8
#define bo8 12
#define bo9 11
#define x1 A2
#define y1 A1
RF24 radio(9, 10);
const byte adresse[6] = "00001";

// Définition de la structure
typedef struct {
  int b1;
  int b2;
  int b3;
  int b4;
  int b5;
  int b6;
  int b7;
  int b8;
  int b9;
  int b0;
  float x;
  float y;
} data;

void setup() {
pinMode(bo1, INPUT_PULLUP);
pinMode(bo, INPUT_PULLUP);
pinMode(bo2, INPUT_PULLUP);
pinMode(bo3, INPUT_PULLUP);
pinMode(bo4, INPUT_PULLUP);
pinMode(bo5, INPUT_PULLUP);
pinMode(bo6, INPUT_PULLUP);
pinMode(bo7, INPUT_PULLUP);
pinMode(bo8, INPUT_PULLUP);
pinMode(bo9, INPUT_PULLUP);
    Serial.begin(115200);
    radio.begin();
    radio.openWritingPipe(adresse);
    radio.setPALevel(RF24_PA_MAX);  // Augmenter la puissance
    radio.stopListening();  // Mode émetteur
}

    // ✅ Créer et initialiser correctement la structure avant l'envoi
void loop() {
    data message;
    message.b0 = digitalRead(bo);
    message.b1 = digitalRead(bo1);
    message.b2 = digitalRead(bo2);
    message.b3 = digitalRead(bo3);
    message.b4 = digitalRead(bo4);
    message.b5 = digitalRead(bo5);
    message.b6 = digitalRead(bo6);
    message.b7 = digitalRead(bo7);
    message.b8 = digitalRead(bo8);
    message.b9 = digitalRead(bo9);
    message.x = analogRead(x1);
    message.y = analogRead(y1);
    if (radio.write(&message, sizeof(message))) {
        Serial.print("✅ Données envoyées -> a: ");
    } else {
        Serial.println("❌ Échec de l'envoi !");
    }

}
