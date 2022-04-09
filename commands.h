
#ifndef commands_
#define commands_

//typedef enum {
enum stateTRIGer {
  IDLE,
  INIT,
  ARM,
  TRIG,
  MAX  // Used in the help for loop to print out.
};

const String TIRG_STATES[] = {"IDLE", "INIT", "ARM", "TRIG", "MAX"} ;

extern stateTRIGer my_stateTRIGer;

void checkCommands(void);
void serialEvent(void);
void establishContact(void);


#endif  //commands.h
