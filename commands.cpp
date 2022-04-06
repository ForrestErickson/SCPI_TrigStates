/*commands
   Process serial port commands
   SCPI like commands. Refere to scpi-99.pdf
   By: Forrest Lee Erickson
   Date: 20210924
   Date: 20220406 Rework for enumerated trigger states.
    These commands cannot be concatenated. Are not parsed for the ";" delimiter.
*/

//--------------- Includes ---------------------------
#include "Arduino.h"
#include "commands.h"

//external variables
extern String inputString ;         // a String to hold incoming data
extern bool isTrigger;
extern bool isLOCK_ON;           // Start out not locking.
extern int RESET_PIN;
extern const String COMPANY;
extern const String MODEL_NAME;
extern const String VERSION;
extern const String LICENSE;


bool stringComplete = false;  // whether the string is complete
//Serial SCPI like commands
const String START = "START";
const String STOP = "STOP";
const String RESET = "RESET"; //Reset Command
const String RST = "*RST";    //Reset command
const String IDN = "*IDN?";   //Identification Query
const String CLS = "*CLS";    //Clear status command
const String LOCK = "LOCK";    //
const String ULOCK = "ULOCK";    //

const String FREQ = "FREQ";    //Set frequency



//typedef enum {
enum stateTRIGer {
  IDLE,
  INIT,
  ARM,
  TRIG,
}
stateTRIGer = IDLE;

//Wait for any character from controller to start data
void establishContact() {
  while (Serial.available() <= 0) {
    delay(300);
    Serial.println("2.5,0");   // send an initial string
  }
  isTrigger = true;
  stateTRIGer = TRIG;
}// end establishContact()

void checkCommands() {
  //Command strings
  // print the string when a newline arrives:
  if (stringComplete) {
    //Serial.println(inputString);    //For debug of command strings
    inputString.toUpperCase();

    if ( inputString.startsWith(CLS)) {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      Serial.println("Clear command status.");
      //To do  Clear ?
      //Set instrument to defaults?
      stateTRIGer = IDLE;
      isTrigger = false;
    }

    if ( inputString.startsWith(LOCK)) {
      //Turn on lock system
      isLOCK_ON = true;
    }
    if ( inputString.startsWith(ULOCK)) {
      //Turn off lock system
      isLOCK_ON = false;
    }

    if ( inputString.startsWith(START)) {
      //      Serial.println("Got command start!");
      stateTRIGer = TRIG;
      isTrigger = true;
    }

    if ( inputString.startsWith(STOP)) {
      //      Serial.println("Got command stop!");
      stateTRIGer = IDLE;
      isTrigger = false;
    }
    if ( inputString.startsWith(RST) || inputString.startsWith(RESET) ) { //Hardware reset.
      Serial.println("Got command to reset!");
      pinMode(RESET_PIN, OUTPUT);
      digitalWrite(RESET_PIN, LOW); // HW Reset
    }
    if ( inputString.startsWith(IDN)) {
      Serial.print(COMPANY); Serial.print(", ");
      Serial.print(MODEL_NAME); Serial.print(", ");
      Serial.print("VERSION: ");
      Serial.println(VERSION);
    }

    //End of strin proccessing so clear the string:
    inputString = "";
    stringComplete = false;
  }// proccessing command strings.
}//end checkCommands


/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}//end serialEvent
