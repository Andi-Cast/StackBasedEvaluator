//Subtract_Command.h
//Andi Castillo-Mauricio

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Subtract_Command : public Command {
public:
 Subtract_Command(Stack <int> & s);
 void execute(void);
 int precedence(void) const;

private:
 Stack <int> & s_;
};

#endif
