//Stack_Command_Factory.cpp
//Andi Castillo-Mauricio

#include "Stack_Command_Factory.h"

//
//Stack_Command_Factory(Stack <int> &)
//
Stack_Command_Factory::Stack_Command_Factory(Stack <int> & s) 
:stack_(s)
{
}

//
//create_num_command(int)
//
Num_Command * Stack_Command_Factory::create_num_command(int number){
 return new Num_Command(stack_, number);
}

//
//create_add_command
//
Add_Command * Stack_Command_Factory::create_add_command(void) {
 return new Add_Command(stack_);
}

//
//create_subtract_command
//
Subtract_Command * Stack_Command_Factory::create_subtract_command(void) {
 return new Subtract_Command(stack_);
}

//
//create_multiply_command
//
Multiply_Command * Stack_Command_Factory::create_multiply_command(void) {
 return new Multiply_Command(stack_);
}

//
//create_divide_commmand
//
Divide_Command * Stack_Command_Factory::create_divide_command(void) {
 return new Divide_Command(stack_);
}

//
//create_modulo_command
//
Modulo_Command * Stack_Command_Factory::create_modulo_command(void) {
 return new Modulo_Command(stack_);
}
