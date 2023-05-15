#include <Servo.h>

Servo servo_left;
Servo servo_right;

int left_read = 2;
int right_read = 3;
int servoLeft = 5;
int servoRight = 6;
int forward = 100;
int backward = 80;

void setup() {
  Serial.begin(9600);
  pinMode(left_read, INPUT);
  pinMode(right_read, INPUT);
  servo_left.attach(servoLeft);
  servo_right.attach(servoRight);
}

void turn_left () {
  servo_left.write(backward);
  servo_right.write(forward);
}

void turn_right () {
  servo_left.write(forward);
  servo_right.write(backward);
}

void go() {
  servo_left.write(forward);
  servo_right.write(forward);
}

void back() {
  servo_left.write(backward);
  servo_right.write(backward);
  //Serial.println('back');
}

void intersection () {
  turn_right();
  delay(250);
  turn_left();
  delay(500);
  turn_right();
  delay(250);
  go();
  delay(250);
}

void loop() {
  int is_left = digitalRead(left_read);
  int is_right = digitalRead(right_read);
  int what = 0;
  if (is_left) what += 2;
  if (is_right) what += 1;
  Serial.println(what);
  switch (what) {
    case 0: 
      go();
      Serial.println("go");
      break;
    case 1: 
      turn_right();
      Serial.println("right");
      break;
    case 2: 
      turn_left();
      Serial.println("left");
      break;
    case 3: 
      intersection();
      Serial.println("intersection");
      break;
  }
}
