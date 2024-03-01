//Add_Command.h
//Andi Castillo-Mauricio

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Add_Command : public Command {
public:
 Add_Command(Stack <int> & s);
 void execute(void); 
 int precedence(void) const;

private:
 ///Stores address of stack that turn infix to postfix
 Stack <int> & s_;
};

#endif
