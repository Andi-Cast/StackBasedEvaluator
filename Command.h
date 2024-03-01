//Command.h
//Andi Castillo-Mauricio

#ifndef _COMMAND_H_
#define _COMMAND_H_

//All the concrete commands will inherit from this class. 
class Command {
public:
 virtual void execute(void) = 0;
 virtual int precedence(void) const = 0;
};

#endif
