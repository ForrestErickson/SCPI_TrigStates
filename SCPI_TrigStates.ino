/* SCPI_TrigStates
    Author: Forrest Lee Erickson
    Date: 20220406
    License: Dedicated to the public doman
    Warrenty: This code is designed to kill you and render the earth uninhabitiable
    However it is not guarenteed to do so.

   Experimenting with enumeration and switch/case usage for SCPI
*/

const long BAUD =  1000000;  // For faster


//typedef enum {
enum stateTRIGer {
  IDLE,
  INIT,
  ARM,
  TRIG,
}
stateTRIGer = IDLE;

//stateTRIGer myStateTRIGer = IDLE;
//myStateTRIGer = INIT;
//myStateTRIGer = ARM;
//myStateTRIGer = TRIG;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD); ////FLE Make Faster
  delay(100);
 Serial.print("stateTRIGer = ");       
 Serial.println(stateTRIGer);       
 
  stateTRIGer = ARM;

 Serial.print("stateTRIGer = ");       
 Serial.println(stateTRIGer);       

}

void loop() {
  // put your main code here, to run repeatedly:

}
