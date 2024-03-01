//Multiply_Command.cpp
//Andi Castillo-Maurcicio

#include "Multiply_Command.h"

//
//Multiply_Command (Stack <int> &)
//
Multiply_Command::Multiply_Command(Stack <int> & s)
:s_(s)
{
}

//
//execute
//
void Multiply_Command::execute(void) {
 int num2 = s_.top();
 s_.pop();
 int num1 = s_.top();
 s_.pop();
 s_.push(num1 * num2);
}

//
//precedence
//
int Multiply_Command::precedence(void) const {
	return 2;
}