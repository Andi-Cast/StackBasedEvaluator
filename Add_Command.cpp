//Add_Command.cpp
//Andi Castillo-Mauricio

#include "Add_Command.h" 

//
//Add_Command(Stack <int> &)
//
Add_Command::Add_Command(Stack <int> & s)
:s_(s)
{
}

//
//execute
//
void Add_Command::execute(void) {
	int num2 = s_.top();
	s_.pop();
	int num1 = s_.top();
	s_.pop();
	s_.push(num1 + num2);
}

//
//precedence
//
int Add_Command::precedence(void) const {
	return 1; 
}
