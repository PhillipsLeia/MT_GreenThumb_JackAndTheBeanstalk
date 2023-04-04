#include <Servo.h>

const int jackDownPin = 2;  //this is the pin for Jack being on the low level
const int jackUpPin = 3;  //this is the pin for Jack being on the high level
const int henDownPin = 4; //this is the pin for Hen being on the low level
const int allUpPin = 5; //this is the pin for everything being on the high level
const int flapPin = 9;  //this is the pin for the flap
const int giantPin = 10;  //this is the pin for the giant 

Servo flap; //servo for flap to be moved 
Servo giant;  //servo for giant to be popped up

int jackDownStatus = 0;
int jackUpStatus = 0;

bool flapUp = true;

void setup() {
  pinMode(jackDownPin, INPUT);
  pinMode(jackUpPin, INPUT);

  flap.attach(9);
  flap.write(0);
}

void loop() {
  jackDownStatus = digitalRead(jackDownPin);
  jackUpStatus = digitalRead(jackUpPin);

  //Checks if Jack has climbed up or down
  if (jackDownStatus == HIGH && !flapUp)
    climbDown();
  else if (jackUpStatus == HIGH && flapUp)
    climbUp();

}

void climbDown(){
  //Flips the flap from down to up
  for (int i = 0; i <= 180; i+=1){
    flap.write(i);
    delay(5);
  }

  flapUp = true;
}

void climbUp(){
  //Flips the flap from up to down
  for (int i = 180; i <= 0; i-=1){
    flap.write(i);
    delay(5);
  }

  flapUp = false;
}
