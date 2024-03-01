//InfixToPostfixConverter.h
//Andi Castillo-Mauricio

#ifndef _INFIXTOPOSTFIXCONVERTER_H_
#define _INFIXTOPOSTFIXCONVERTER_H_

#include <sstream> //used for the istringstream
#include "Stack.h"
#include "Array.h"
#include "Stack_Command_Factory.h"

class InfixToPostfixConverter {
public:
 //Initializing constructor. 
 InfixToPostfixConverter(std::string & input, Stack_Command_Factory & factory, Array<Command*> & postfix);

 //This will do the converting of the infix string to postfix.
 //It will return an array of commands in postfix order.
 Array<Command *> convert();

private:
 std::string infix_;
 Stack_Command_Factory factory_;
 Array<Command *> postfix_;
};

#endif
