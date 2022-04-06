# SCPI_TrigStates
Experimenting with enumeration and switch/case usage for SCPI.  Process serial port commands    SCPI like commands.


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

/*commands
   Process serial port commands  
   SCPI like commands. Refere to scpi-99.pdf  
   By: Forrest Lee Erickson  
   Date: 20210924  
   Date: 20220406 Rework for enumerated trigger states.  
    These commands cannot be concatenated. Are not parsed for the ";" delimiter.  
*/
