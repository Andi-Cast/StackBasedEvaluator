//Num_Command.cpp
//Andi Castillo-Mauricio

#include "Num_Command.h"
#include <iostream>

//
//Num_Command(Stack <int> &)
//
Num_Command::Num_Command(Stack <int> & s, int num)
:s_(s),
 num_(num)
{
}

//
//execute
//
void Num_Command::execute(void) {
 s_.push (num_);
}

//
//precedence
//
int Num_Command::precedence(void) const {
 return 3;
}
