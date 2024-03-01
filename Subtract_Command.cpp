//Subtract_Command.cpp
//Andi Castillo-Mauricio

#include "Subtract_Command.h"

//
//Subtract_Command(Stack <int> &)
//
Subtract_Command::Subtract_Command(Stack <int> & s)
:s_(s)
{
}

//
//execute
//
void Subtract_Command::execute(void) {
 int num2 = s_.top();
 s_.pop();
 int num1 = s_.top();
 s_.pop();
 s_.push(num1 - num2);
}

//
//precedence
//
int Subtract_Command::precedence(void) const {
	return 1;
}
