

#include <BluetoothSerial.h>

// Create a Bluetooth Serial object
BluetoothSerial SerialBT ;
// Create a Bluetooth Serial object

// Pin definitions
const int mot1s1=27;
const int mot1s2=26;
const int mot2s1=25;
const int mot2s2=33;
const int ENA=4;
const int ENB=2;
char a9ra ;


char command;
char X;

void setup() {
  pinMode(mot1s1,OUTPUT);
  pinMode(mot1s2,OUTPUT);
  pinMode(mot2s1,OUTPUT);
  pinMode(mot2s2,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  Serial.begin(9600);
  SerialBT.begin("FACROON");
  STOP();
  Serial.println("achref ");
  analogWrite(ENA,255);
      analogWrite(ENB,255);
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
  while (SerialBT.available()) {
    command = SerialBT.read();
    if(command=='1'){
      analogWrite(ENA,25);
      analogWrite(ENB,25);
      
  }
    else if(command=='2'){
      analogWrite(ENA,50);
      analogWrite(ENB,50);
      
  }
    else if(command=='3'){
      analogWrite(ENA,75);
      analogWrite(ENB,75);
      
  }
    else if(command=='4'){
      analogWrite(ENA,100);
      analogWrite(ENB,100);
      
  }
    else if(command=='5'){
      analogWrite(ENA,125);
      analogWrite(ENB,125);
    
  }
    else if(command=='6'){
      analogWrite(ENA,175);
      analogWrite(ENB,175);
      
  }
    else if(command=='7'){
      analogWrite(ENA,200);
      analogWrite(ENB,200);
     
  }
    else if(command=='8'){
      analogWrite(ENA,225);
      analogWrite(ENB,225);
     
  }
    else if(command=='9'){
      analogWrite(ENA,250);
      analogWrite(ENB,250);
    
  }
    else if(command=='q'){
      analogWrite(ENA,250);
      analogWrite(ENB,250);
      
  } 
  else {
    sou9(command);
  } 
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







