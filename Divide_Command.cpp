//Divid_Command.cpp
//Andi Castillo-Mauricio

#include "Divide_Command.h"

//
//Divide_Command(Stack <int> &)
//
Divide_Command::Divide_Command(Stack <int> & s) 
:s_(s)
{
}

//
//execute
//
void Divide_Command::execute(void) {
 int num2 = s_.top();
 s_.pop();
 int num1 = s_.top();
 s_.pop();
 s_.push(num1 / num2);
}

//
//precedence
//
int Divide_Command::precedence(void) const {
	return 2;
}
