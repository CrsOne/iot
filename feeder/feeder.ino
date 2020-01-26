#include <DS1302RTC.h>
#include <Time.h>
#include <Stepper.h>
#define STEPS 200

const int stepsPerRevolution = 200;
Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);
DS1302RTC rtc(4, 6, 5);

int previous = 0;


void setup() {
  stepper.setSpeed(100);
  Serial.begin(9600);
  if (rtc.haltRTC()) {
    Serial.print("Clock stopped!");
  }
  else {
    Serial.print("Clock working.");
  }
  setSyncProvider(rtc.get); // the function to get the time from the RTC
  if (timeStatus() == timeSet) {
    Serial.print(" Ok!");
  }
  else {
    Serial.print(" FAIL!");
  }
}

void loop() {
  digitalClockDisplay();
  while (hour() >= 0 ){//and (minute() >= 38 and minute() <= 50)) {
    rotateMotor();


  }
  
}
void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();

}


void printDigits(int digits) {
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void rotateMotor() {
  stepper.step(-stepsPerRevolution);

}
