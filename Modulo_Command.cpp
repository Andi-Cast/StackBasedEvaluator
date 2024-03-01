//Modulo_Command.cpp
//Andi Castillo-Mauricio

#include "Modulo_Command.h"

//
//Modulo_Command(Stack <int> &)
//
Modulo_Command::Modulo_Command(Stack <int> & s)
:s_(s)
{
}

//
//execute
//
void Modulo_Command::execute(void) {
 int num2 = s_.top();
 s_.pop();
 int num1 = s_.top();
 s_.pop();
 s_.push(num1 % num2);
}

//
//precedence
//
int Modulo_Command::precedence(void) const {
	return 2;
}
