
#include <HCSR04.h>

HCSR04 hc1(4, 5); // Initialization of HCSR04 class (trig pin, echo pin)

// Pin definitions

const int mot1s1 = 3;
const int mot1s2 = 2;
const int mot2s1 = 7;
const int mot2s2 = 8;
const int ENA = 9;
const int ENB = 10;
char I;

// Variables
// Ensure it's initialized

void setup() {

  Serial.begin(9600);

  // Pin modes
  pinMode(mot1s1, OUTPUT);
  pinMode(mot1s2, OUTPUT);
  pinMode(mot2s1, OUTPUT);
  pinMode(mot2s2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Enable motor drivers
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void loop() {

  char x = Serial.read();
  x="";
  I="";

  // Main loop to check for 'F' or perform actions
  while (!(x == 'F' || I == 'F')) {
    for (int i = 0; i <= 4; i++) {
      x = Serial.read();
      if (x == 'F') {
        I = x;
        break;}
      else {
        left();
        delay(250);
        stop();
        delay(500);
      }
    }

    for (int i = 0; i <= 5; i++) {
      float d1 = hc1.dist();
      Serial.println(d1);
      x = Serial.read();
      if (x == 'F') {
        I = x;
        break;}
       else {
        if (d1 > 2 && d1 <= 30) {
          left();
          delay(250);
          stop();
          delay(500);
        } else {
          forward();
          delay(250);
          stop();
          delay(500);
        }
      }
    }
  }

  stop();

  // Reading from red2
  int x2 = digitalRead(red2);
  for (int i = 0; i <= 100; i++) {
    x2 = digitalRead(red2);
    Serial.println(x2);
    if (x2 >= 0 && x2 < 1) {
      break;
    } else {
      forward();
      delay(250);
      stop();
      delay(500);
    }
  }

  // Injection loop
  while (true) {
    x2 = digitalRead(red2);
    delay(10);
    if (x2 == 0) {
      injection();
    } else {
      break;
    }
  }
}

void injection() {
  stop();
  servo();
}

void servo() {
  for (int i = 0; i <= 90; i += 5) {
    myservo.write(i);
    digitalWrite(13, HIGH);
    delay(600);
  }

  for (int i = 90; i >= 0; i -= 5) {
    myservo.write(i);
    digitalWrite(13, HIGH);
    delay(600);
  }
   digitalWrite(13, LOW);
}

void right() {
  digitalWrite(mot1s1, HIGH);
  digitalWrite(mot1s2, LOW);
  digitalWrite(mot2s1, HIGH);
  digitalWrite(mot2s2, LOW);
}

void forward() {
  digitalWrite(mot1s1, HIGH);
  digitalWrite(mot1s2, LOW);
  digitalWrite(mot2s1, HIGH);
  digitalWrite(mot2s2, LOW);
}

void left() {
  digitalWrite(mot1s1, HIGH);
  digitalWrite(mot1s2, LOW);
  digitalWrite(mot2s1, LOW);
  digitalWrite(mot2s2, HIGH);
}

void stop() {
  digitalWrite(mot1s1, LOW);
  digitalWrite(mot1s2, LOW);
  digitalWrite(mot2s1, LOW);
  digitalWrite(mot2s2, LOW);
}
