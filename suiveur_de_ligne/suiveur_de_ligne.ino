#include <AFMotor.h>
#include <HCSR04.h>
#include <Servo.h>
Servo servo;
HCSR04 ul(3,4);
 AF_DCMotor motor1(1);
 AF_DCMotor motor2(2);
 int capt1=5;
 int capt2=6;
 int led=7;
 bool val1;
 bool val2;
 float val3;
 float val4;
 const int dis=5;
void setup() {
  servo.attach(8);
  pinMode(capt1,INPUT);
  pinMode(capt2,INPUT);
  pinMode(led,OUTPUT);
  digitalWrite(led,1);
}

void loop() {
  val3=ul.dist();
  val1=digitalRead(capt1);
  val2=digitalRead(capt2);
  if ( val3<dis){
  if(val1 && val2 ){
    stop();



  }
  else if (!val1 && !val2 ){
    forward();
  }
  else if(!val1 || !val2 ){
    if (!val1){
      right();
    }
    else{
      left();
    }
  }
  else{
    karar();
  }

  // put your main code here, to run repeatedly:
  }
void stop(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
void right(){
  motor1.setSpeed(200);
  motor1.run(FORWARD);
  delay(100);
  motor2.run(RELEASE);
  motor2.setSpeed(100);
  motor2.run(BACKWARD);
  delay(100);
}
void left(){
  motor1.setSpeed(100);
  motor1.run(BACKWARD);
  delay(100);
  motor2.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(FORWARD);
  delay(100);
  motor2.run(RELEASE);
}
void forward(){
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
void karar(){
  servo.write(90);
  val3=ul.dist();
  servo.write(-90);
  val4=ul.dist();
  if (val4<val3){
    right();
    forward();
    delay(500);
    left();
    forward();
    delay(500);
    left();
    forward();
    delay(500);
    right();
  }
  else{
    left();
    forward();
    delay(500);
    right();
    forward();
    delay(500);
    right();
    forward();
    delay(500);
    left();

  }

  }

