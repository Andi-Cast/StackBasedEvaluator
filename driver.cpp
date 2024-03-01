//driver.cpp
//Andi Castillo-Mauricio

#include <iostream>
#include <sstream> //used for istringstream to parse input
#include "InfixToPostfixConverter.h"
#include "Add_Command.h"
#include "Num_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Subtract_Command.h"
#include "Modulo_Command.h"
#include "Stack_Command_Factory.h"


int main() {
 //Stack that stores the final result and the stack which 
 //all the commands interact with.
 Stack<int> result;
 
 //Factory that will create all the commands.
 Stack_Command_Factory factory(result);

 //This will be used to check if the user is still active.
 bool Active = true;

 while(Active == true) {
  std::string infix;
  std::cout<<"Calculate: ";
  std::getline(std::cin, infix);
  
  //Checks if user want to quit program.
  if(infix == "QUIT"){
   return 0;
  }

  //This array will hold Command* in postfix which will be done by
  //the InfixToPostfixConverter.converter()
  Array <Command *> postfix(10);
     
  //This will do the converting of the infix string to postfix. 
  InfixToPostfixConverter converter(infix, factory, postfix);

  //This will store the array that holds the commands.
  postfix = converter.convert();
  
  //This will iterate through the array and execute the commands.
  for(int i = 0; i < postfix.size(); i++) {
    if(postfix[i] != nullptr) {
     postfix[i]->execute();
    }
  } 

  //Final solution should be on top of the stack.
  if(result.size() == 1) {
   int solution = result.top();
   std::cout<<"Answer: "<< solution << std::endl;
  
   //Empties the stack so there is nothing left on the stack. 
   result.clear();
  }
  //If there is more than one value on the stack then an error message will 
  //be displayed and the stack will be reset for next calculation. 
  else {
   std::cout<<"Invalid expression. Try again."<<std::endl;
   result.clear();
  }
 }
 return 0;
}//
