//Stack_Command_Factory.h
//Andi Castillo-Mauricio

#ifndef _STACK_COMMAND_FACTORY_H_
#define _STACK_COMMAND_FACTORY_H_

#include "Abstract_Command_Factory.h"
#include "Stack.h"

//Each method is responsible for creating a concrete command.

class Stack_Command_Factory : public Abstract_Command_Factory {
public:
 Stack_Command_Factory(Stack <int> & s);
 Num_Command * create_num_command(int number);
 Add_Command * create_add_command(void);
 Subtract_Command * create_subtract_command(void);
 Multiply_Command * create_multiply_command(void);
 Divide_Command * create_divide_command(void);
 Modulo_Command * create_modulo_command(void);

private:
 Stack <int> & stack_; 
};

#endif
