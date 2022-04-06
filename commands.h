
#ifndef commands_
#define commands_

//typedef enum {
enum stateTRIGer {
  IDLE,
  INIT,
  ARM,
  TRIG,
};

//extern stateTRIGer my_stateTRIGer = IDLE;
extern stateTRIGer my_stateTRIGer;

void checkCommands(void);
void serialEvent(void);
void establishContact(void);


#endif  //commands.h
