#include <AccelStepper.h>
#include <MultiStepper.h>

#define HALFSTEP 8

// Motor pin definitions

#define motorPin1 3 // IN1 on the ULN2003 driver 1

#define motorPin2 4 // IN2 on the ULN2003 driver 1

#define motorPin3 5 // IN3 on the ULN2003 driver 1

#define motorPin4 6 // IN4 on the ULN2003 driver 1

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48 
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {

stepper1.setMaxSpeed(1200.0); 
//1200 is maximum speed otherwise the motor will stall stepper1.(200.0); 
//this i find the best acceleration speed  stepper1.moveTo(100000);
//the more step the longer the drill spins

//if the drill spins in the wrong way add a -
stepper1.setAcceleration(200);
stepper1.moveTo(-100000);

}

void loop() {

  stepper1.run(); 

}
