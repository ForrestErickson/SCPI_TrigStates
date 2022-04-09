/* SCPI_TrigStates
    Author: Forrest Lee Erickson
    Date: 20220406
    License: Dedicated to the public doman
    Warrenty: This code is designed to kill you and render the earth uninhabitiable
    However it is not guarenteed to do so.

   Experimenting with enumeration and switch/case usage for SCPI
   Much of this was copied over from PDSArduino.ino
   The RESET_PIN assumes the connection on the OctoUNO board.
*/

#include "wink.h"
#include "commands.h"

//Hardware setup
extern const int RESET_PIN = 12;   // To Drive HW Reset. Connect D12 to RES through 1K.

//Some program constants
//const char COMPANY[] PROGMEM = {"Amused Scientist"};
extern const String COMPANY = "Amused Scientist";
extern const String MODEL_NAME = "SCPI_TrigStates";
extern const String VERSION = "0.0.1";    //Add serial commands
extern const String LICENSE = "Public Domain";    //
extern const String WARRANTY = "NONE";    //

const long BAUD =  1000000;  // For faster

//String variable global
String inputString = "";         // a String to hold incoming data
bool isTrigger = false;           // Start out not triggered.
bool isLOCK_ON = false;           // Start out not locking.


extern stateTRIGer my_stateTRIGer = IDLE ; //myStateTRIGer; in commands.h

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD); ////FLE Make Faster
  delay(100);
  //Splash message serial port
  Serial.println();
  Serial.print(COMPANY); Serial.print(", ");
  Serial.print(MODEL_NAME); Serial.print(", ");
  Serial.print("VERSION: ");
  Serial.println(VERSION);
  Serial.print("LICENSE: ");
  Serial.println(LICENSE);
  Serial.print("WARRANTY: ");
  Serial.println(WARRANTY);

  Serial.print("Instrument status: ");
  Serial.print("nstateTRIGer = ");
  Serial.println(my_stateTRIGer);

}//end setup()

void loop() {
  // put your main code here, to run repeatedly:
  winkLED_BUILTIN(); //the built in LED.
  checkCommands();

}
