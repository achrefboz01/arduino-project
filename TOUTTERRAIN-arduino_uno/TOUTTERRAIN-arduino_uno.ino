
const int mot1s1=2;
const int mot1s2=3;
const int mot2s1=4;
const int mot2s2=5;
char a9ra ;


char command;
char X;

void setup() {
  pinMode(mot1s1,OUTPUT);
  pinMode(mot1s2,OUTPUT);
  pinMode(mot2s1,OUTPUT);
  pinMode(mot2s2,OUTPUT);
  Serial.begin(9600);
  STOP();
  Serial.println("achref ");
}

void RIGHT() {
 digitalWrite(mot1s1,1);
  digitalWrite(mot1s2,0);
  digitalWrite(mot2s2,0);
  digitalWrite(mot2s1,1);

}

void LEFT() {
  digitalWrite(mot1s1,0);
  digitalWrite(mot1s2,1);
  digitalWrite(mot2s2,1);
  digitalWrite(mot2s1,0);

}

void BACK() {
   digitalWrite(mot1s1,0);
  digitalWrite(mot1s2,1);
  digitalWrite(mot2s2,0);
  digitalWrite(mot2s1,1);
}

void FWD() {
   digitalWrite(mot1s1,1);
  digitalWrite(mot1s2,0);
  digitalWrite(mot2s2,1);
  digitalWrite(mot2s1,0);
}

void UP_RIGHT() {
 digitalWrite(mot1s1,1);
  digitalWrite(mot1s2,0);
  digitalWrite(mot2s2,0);
  digitalWrite(mot2s1,0);
}

void DOWN_LEFT() {
   digitalWrite(mot1s1,0);
  digitalWrite(mot1s2,1);
  digitalWrite(mot2s2,0);
  digitalWrite(mot2s1,0);
}

void DOWN_RIGHT() {
   digitalWrite(mot1s1,0);
  digitalWrite(mot1s2,0);
  digitalWrite(mot2s2,0);
  digitalWrite(mot2s1,1);
}

void UP_LEFT() {
   digitalWrite(mot1s1,0);
  digitalWrite(mot1s2,0);
  digitalWrite(mot2s2,1);
  digitalWrite(mot2s1,0);
}

void STOP() {
   digitalWrite(mot1s1,0);
  digitalWrite(mot1s2,0);
  digitalWrite(mot2s2,0);
  digitalWrite(mot2s1,0);
}

void loop() {
  while (Serial.available()) {
    command = Serial.read();
    sou9(command);
  } 

}
void sou9(char X){
      if (command == 'F') {
        FWD();
      
    } else if (command == 'B') {
        BACK();
    } else if (command == 'R') {
        RIGHT();
    } else if (command == 'L') {
        LEFT();
    } else if (command == 'G') {
        UP_LEFT();
    } else if (command == 'I') {
        UP_RIGHT();
    } else if (command == 'H') {
        DOWN_LEFT();
    } else if (command == 'J') {
        DOWN_RIGHT();
    } else {
        STOP();
    }
  }







