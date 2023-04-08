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

bool flapUp = true; //if the flap is currently up
bool giantOut = false; //if the giant is out

void setup() {
  pinMode(jackDownPin, INPUT);
  pinMode(jackUpPin, INPUT);

  flap.attach(flapPin);
  flap.write(20);
}

void loop() {
  jackDownStatus = digitalRead(jackDownPin);
  jackUpStatus = digitalRead(jackUpPin);

  //Checks if Jack has climbed up or down
  if (jackDownStatus == HIGH && !flapUp)
  {
    climbDown();
    Serial.println("Down");
  }
    
  else if (jackUpStatus == HIGH && flapUp)
  {
    climbUp();
    Serial.println("Up");
  }

}

//Flips the flap from down to up
void climbDown(){
  for (int i = 180; i >= 20; i-=1){
    flap.write(i);
    delay(5);
  }

  flapUp = true;
}

//Flips the flap from up to down
void climbUp(){
  for (int i = 20; i <= 175; i+=1){
    flap.write(i);
    delay(5);
  }

  flapUp = false;
}
