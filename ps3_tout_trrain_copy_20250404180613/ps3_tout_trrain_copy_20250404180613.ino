#include <Ps3Controller.h>

const uint8_t ENA = 4;
const uint8_t IN1 = 27;
const uint8_t IN2 = 26;
const uint8_t ENB = 2;
const uint8_t IN3 = 25;
const uint8_t IN4 = 33;




void setup() {
    Serial.begin(115200);
   
    Ps3.begin("94:54:c5:b7:e5:de");
    Serial.println("Ready.");// Remplacez par l'adresse MAC de votre manette
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
}

void stopp() {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, 0);
}

void forward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
}

void backward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
}

void gauche() {
    
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
}

void droit() {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
}
void UP_RIGHT() {
 digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN2,0);
  digitalWrite(IN1,0);
}

void DOWN_LEFT() {
   digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN2,0);
  digitalWrite(IN1,0);
}

void DOWN_RIGHT() {
   digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN2,0);
  digitalWrite(IN1,1);
}

void UP_LEFT() {
   digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN2,1);
  digitalWrite(IN1,0);
}



void loop()
{
    if(Ps3.isConnected()){
       if (Ps3.data.button.r1) {
            backward();
            Serial.println("Recule");
        } else if (Ps3.data.button.circle) {
            droit();
            Serial.println("Droite");
        }
         else if (Ps3.data.button.l1) {
            forward();
            Serial.println("UP");}
        else if ( Ps3.data.button.square) {
            gauche();
            Serial.println("Gauche");
        
        } 
    else {
            stopp();
            Serial.println("Stop");
        } 
        }
    }


       