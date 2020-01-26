#include <WiFiClientSecure.h>
#include <WiFiServerSecureBearSSL.h>
#include <ESP8266WiFiType.h>
#include <ESP8266WiFi.h>
#include <CertStoreBearSSL.h>
#include <WiFiServer.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClient.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiGeneric.h>
#include <BearSSLHelpers.h>
#include <WiFiServerSecure.h>
#include <ESP8266WiFiAP.h>
#include <WiFiUdp.h>

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
   Serial.begin(115200);
  Serial.setDebugOutput(true);
//  if (rtc.haltRTC()) {
//    Serial.print("Clock stopped!");
//  }
//  else {
//    Serial.print("Clock working.");
//  }
//  setSyncProvider(rtc.get); // the function to get the time from the RTC
//  if (timeStatus() == timeSet) {
//    Serial.print(" Ok!");
//  }
//  else {
//    Serial.print(" FAIL!");
//  }
//  Serial.println();

ESP.wdtDisable();

  WiFi.begin("Casa_VM", "660f97a209");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  digitalClockDisplay();
  while (hour() >= 0 ) { //and (minute() >= 38 and minute() <= 50)) {
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
