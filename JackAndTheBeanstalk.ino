#include <Servo.h>

const int jackDownPin = 2;  //this is the pin for Jack being on the low level
const int jackUpPin = 3;  //this is the pin for Jack being on the high level
const int henDownPin = 4; //this is the pin for Hen being on the low level
const int allUpPin = 5; //this is the pin for everything being on the high level
const int flapPin = 9;  //this is the pin for the flap
const int giantPin = 10;  //this is the pin for the giant 

Servo flap; //servo for flap to be moved 
Servo giant;  //servo for giant to be popped up

int jackDownStatus = 0; //if jack is detected at the bottom of the beanstalk
int jackUpStatus = 0; //if jack is detected at the top of the beanstalk
int henDownStatus = 0; //if the hen is detected on the bottom floor
int allUpStatus = 0; //if all of the giants stuff is detected on the top floor

bool isFlapUp = true; //if the flap is currently up
bool giantOut = false; //if the giant is out

int flapUp = 0;
int flapDown = 170;

void setup() {
  pinMode(jackDownPin, INPUT);
  pinMode(jackUpPin, INPUT);
  pinMode(henDownPin, INPUT);
  pinMode(allUpPin, INPUT);

  flap.attach(flapPin);
  flap.write(flapUp);

  giant.attach(giantPin);
  giant.write(0);
}

void loop() {
  jackDownStatus = digitalRead(jackDownPin);
  jackUpStatus = digitalRead(jackUpPin);

  henDownStatus = digitalRead(henDownPin);
  allUpStatus = digitalRead(allUpPin);

  //Checks if Jack has climbed up or down
  if (jackDownStatus == HIGH && !isFlapUp)
    climbDown();
  else if (jackUpStatus == HIGH && isFlapUp)
    climbUp();

  // checks if the giant should appear or disappear
  if (henDownStatus == HIGH && !giantOut)
    giantAppears();
  else if (allUpStatus == HIGH && giantOut)
    giantDisappears();

}

//flips the flap from down to up
void climbDown(){
  for (int i = flapDown; i >= flapUp; i-=1){
    flap.write(i);
    delay(5);
  }

  isFlapUp = true;
}

//flips the flap from up to down
void climbUp(){
  for (int i = flapUp; i <= flapDown; i+=1){
    flap.write(i);
    delay(5);
  }

  isFlapUp = false;
}

//flips the giant around so he appears on the bottom floor
void giantAppears(){
  for (int i = 0; i <= 180; i += 1) {
    giant.write(i);
    delay(5);
  }
  
  giantOut = true;
}

//flips the giant around so he disappears from the bottom floor
void giantDisappears(){
  for (int i = 180; i >= 0; i -= 1) {
    giant.write(i);
    delay(5);
  }
  
  giantOut = false;
}

