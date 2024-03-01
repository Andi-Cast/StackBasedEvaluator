//Multiply_Command.h
//Andi Castillo-Mauricio

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Multiply_Command : public Command {
public:
 Multiply_Command(Stack <int> & s);
 void execute(void);
 int precedence(void) const;

private:
 Stack <int> & s_;
};

#endif
