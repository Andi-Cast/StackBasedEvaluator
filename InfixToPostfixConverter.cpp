//InfixToPostfixConverter.cpp
//Andi Castillo-Mauricio

#include "InfixToPostfixConverter.h"
#include <iostream> 

//
//InfixToPostfixConverter(string, Stack_Command_Factory, Array<Command*>)
//
InfixToPostfixConverter::InfixToPostfixConverter(std::string & input, Stack_Command_Factory & factory, Array<Command *> & postfix) 
:infix_(input),
 factory_(factory),
 postfix_(postfix)
{
}

//
//convert
//
Array<Command *>  InfixToPostfixConverter::convert() {
 std::istringstream ss(infix_);
 std::string token;

 Command * command = 0;

 Stack <Command *> operatorStack;

 int arrayIndex = 0;

 while(ss >> token) {
  //This if statement checks to see if the postfix <Command*> array
  //has enough space to add the incoming command. If there isn't enough
  //space, more is allocated.  
  if(arrayIndex >= postfix_.size()) {
   postfix_.resize(postfix_.size() * 2);
  }	  
	 
  if(isdigit(token[0]) == true || isdigit(token[1]) == true) {
   int number = stoi(token);
   command = factory_.create_num_command(number);
   postfix_[arrayIndex] = command;
   arrayIndex++;
  }
  else if(token == "(") {
   //I used a nullptr as a place holder for the open parenthesis.
   //I chose this design to avoid creating another object and allocate
   //memory to an objects whose methods didn't make sense. 
   operatorStack.push(nullptr);
  }
  else if(token == ")") {
   //Pops operators off the stack and add them to the postfix array until
   //the open parenthesis is reached(nullptr).
   while(!operatorStack.is_empty() && operatorStack.top() != nullptr) {
    postfix_[arrayIndex] = operatorStack.top();
    arrayIndex++;
    operatorStack.pop();
   }
   //This will remove the open parenthesis from stack.
   operatorStack.pop();
  }
  else {
   if(token == "+") {
    command = factory_.create_add_command();
   }
   else if(token == "-") {
    command = factory_.create_subtract_command();
   }
   else if(token == "*") {
    command = factory_.create_multiply_command();
   }
   else if(token == "/") {
    command = factory_.create_divide_command();
   }
   else if(token == "%") {
    command = factory_.create_modulo_command();
   }

   //If operator stack is empty, the operator will be pushed to the stack.
   //This also checks if the top is a nullptr indicating that an open
   //parenthesis was incountered. The reason is because the open parenthesis 
   //doesn't have a corresponding object or  precedence() method to check so 
   //the incoming command is automatically added on top of the stack. 
   if(operatorStack.is_empty() || operatorStack.top() == nullptr) {
    operatorStack.push(command);
   }
        
   //If the stack is not empty, precedence will be checked.
   else {
    //If incoming token precedence is greater than the operator on top of the stack, the
    //token will be pushed onto the stack.
    if(operatorStack.top()->precedence() < command->precedence()) {
     operatorStack.push(command);
    }
        
    //If the incoming token precedence is less than or equal to the operator on top of the stack,
    //the operator on top will be added to the postfix string and the removed from the stack. The incoming
    //token will then be pushed onto the stack.
    else {
     postfix_[arrayIndex] = operatorStack.top();
     arrayIndex++;
     operatorStack.pop();
     operatorStack.push(command);
    }
   }
  }
 }      

 //This will empty the stack with the remaining operator(s).
 while(!operatorStack.is_empty()){
  postfix_[arrayIndex] = operatorStack.top();
  arrayIndex++;
  operatorStack.pop();
 }
 return postfix_;
}
