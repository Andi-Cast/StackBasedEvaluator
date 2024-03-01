//Divide_Command.h
//Andi Castillo-Mauricio

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Divide_Command : public Command {
public:
 Divide_Command(Stack <int> & s);
 void execute(void);
 int precedence(void) const;

private:
 Stack <int> & s_; 
};

#endif
