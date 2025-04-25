#include <SPI.h>
#include <RF24.h>
#include<Servo.h>
#define mot1s1 27
#define mot1s2 26
#define mot2s1 28
#define mot2s2 29
#define ENA 24
#define ENB 25
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
RF24 radio(7, 8);
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
  int x;
  int y;
} data;
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
void stop() {
   digitalWrite(mot1s1,0);
  digitalWrite(mot1s2,0);
  digitalWrite(mot2s2,0);
  digitalWrite(mot2s1,0);
}

void setup() {
   pinMode(mot1s1,OUTPUT);
  pinMode(mot1s2,OUTPUT);
  pinMode(mot2s1,OUTPUT);
  pinMode(mot2s2,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
    servo.attach(3);
  servo1.attach(4);
   servo2.attach(5);
  servo3.attach(6);
    servo4.attach(7);
    Serial.begin(9600);
    radio.begin();
    radio.openReadingPipe(1, adresse);
    radio.setPALevel(RF24_PA_MAX);
    radio.startListening();  // Mode récepteur
}
void loop() {
  data ch;
    if (radio.available()) {
      
       radio.read(&ch, sizeof(ch));
       Serial.println(ch.x);
              Serial.println(ch.y);
               Serial.println(ch.b4);
              Serial.println(ch.b1);
               Serial.println(ch.b2);
              Serial.println(ch.b3);

    if (ch.b0==0){
    while(ch.b0!=1){
      for(int i=a;i<=180;i+=5){
        servo.write(i);
        a=i;
        radio.read(&ch, sizeof(ch));
          if(ch.b0==1){
            break;
          }

      }
      break;
    }
  }
  else if (ch.b1==0){
    while(ch.b1!=1){
      for (int j = a; j >= 0; j -= 5) {
        servo.write(j);
  
          a=j;
        radio.read(&ch, sizeof(ch));

          if(ch.b1==1){
            //.println("b");
            break;
          }

      }
      break;
    }
  }
   else if (ch.b2==0){
    while(ch.b2!=1){
      for(int i=b;i<=180;i+=5){
        servo1.write(i);
        b=i;
            //.println(b);

          radio.read(&ch, sizeof(ch));
          if(ch.b2==1){
            break;
          }

      }
      break;
    }
  }
  else if (ch.b3==0){
    while(ch.b3!=1){
      for (int j = b; j >= 0; j -= 5) {
        servo1.write(j);
  
          b=j;
          radio.read(&ch, sizeof(ch));
          if(ch.b3==1){
            //.println("b");
            break;
          }

      }
      break;
    }
  }
  // put your main code here, to run repeatedly:
else if (ch.b4==0){
    while(ch.b4!=1){
      for(int i=c;i<=180;i+=5){
        servo2.write(i);
        c=i;
            //.println(c);

          radio.read(&ch, sizeof(ch));
          if(ch.b4==1){
            break;
          }

      }
      break;
    }
  }
  else if (ch.b5==0){
    while(ch.b5!=1){
      for (int j = c; j >= 0; j -= 5) {
        servo2.write(j);
  
          c=j;
          radio.read(&ch, sizeof(ch));
          if(ch.b5==1){
            //.println("b");
            break;
          }

      }
      break;
    }
  }
  
   else if (ch.b6==0){
    while(ch.b6!=1){
      for(int i=d;i<=180;i+=5){
        servo3.write(i);
        d=i;
            //.println(d);

         radio.read(&ch, sizeof(ch));
          if(ch.b6==1){
            break;
          }

      }
      break;
    }
  }
  else if (ch.b7==0){
    while(ch.b7!=1){
      for (int j = d; j >= 0; j -= 5) {
        servo3.write(j);
  
          d=j;
          radio.read(&ch, sizeof(ch));
          if(ch.b7==1){
            //.println("b");
            break;
          }

      }
      break;
    }
  }
   else if (ch.b8==0){
    while(ch.b8!=1){
      for(int i=e;i<=180;i+=5){
        servo4.write(i);
        e=i;
            //.println(e);

          radio.read(&ch, sizeof(ch));
          if(ch.b8==1){
            break;
          }

      }
      break;
    }
  }
  else if (ch.b9==0){
    while(ch.b9!=1){
      for (int j = e; j >= 0; j -= 5) {
        servo4.write(j);
  
          e=j;
          radio.read(&ch, sizeof(ch));
          if(ch.b9==1){
            //.println("b");
            break;
          }

      }
      break;
    }
  }
else if (ch.x>550){
  int p=map(int(ch.x),0,1024,0,255);
       analogWrite(ENA,p);
       analogWrite(ENB,p); 
        FWD();
}
else if (ch.x<500){
  int p=map(int(ch.x),0,1024,0,255);
       analogWrite(ENA,p);
       analogWrite(ENB,p); 
        BACK();
}
else if (ch.y>550){
 
        RIGHT();
}
else if (ch.y<500){
  
        LEFT();
}
else{
  stop();
}
    }
    
}


