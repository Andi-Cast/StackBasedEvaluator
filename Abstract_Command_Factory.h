//Abstract_Command_Factory.h
//Andi Castillo-Mauricio

#ifndef _ABSTRACT_COMMAND_FACTORY_H_
#define _ABSTRACT_COMMAND_FACTORY_H_

#include "Num_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"

class Abstract_Command_Factory {
public:
 virtual Num_Command * create_num_command(int number) = 0;
 virtual Add_Command * create_add_command(void) = 0;
 virtual Subtract_Command * create_subtract_command(void) = 0;
 virtual Multiply_Command * create_multiply_command(void) = 0;
 virtual Divide_Command * create_divide_command(void) = 0;
 virtual Modulo_Command * create_modulo_command(void) = 0;
};

#endif
