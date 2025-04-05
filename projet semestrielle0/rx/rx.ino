#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<Servo.h>
Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
RF24 radio(9, 10);
const byte adresse[6] = "00001";
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
    servo.attach(3);
  servo1.attach(4);
   servo2.attach(5);
  servo3.attach(6);
    servo4.attach(7);
    Serial.begin(115200);
    radio.begin();
    radio.openReadingPipe(1, adresse);
    radio.setPALevel(RF24_PA_MAX);
    servo.attach(6);
    radio.startListening();  // Mode récepteur
}

void loop() {
  data ch1;
    if (radio.available()) {
          // Initialise la variable pour éviter les erreurs
       radio.read(&ch1, sizeof(ch1));
      Serial.print("a= ");
        Serial.print(ch1.a);
         Serial.print(" b= ");
        Serial.print(ch1.b);
         Serial.print(" ch=");
        Serial.println(ch1.ch);
        servo.write(ch1.a);
        delay(500);
         Serial.print(" servo pos=");
        Serial.println(servo.read());
        servo.write(int(ch1.b));
        delay(500);
Serial.print(" servo pos=");
        Serial.println(servo.read());


  
    }
    
    
}


