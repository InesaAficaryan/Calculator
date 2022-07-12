#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>
#include <stack>

// The type is equal 0 if it is number, and is equal +, -, etc if it is add, diff....
struct Lexeme
{
	char type; 
	double value;

};

// This function is for determining the order of the operator, it takes the operator op as input and returns 1 if the operator equals + or -, and if the operator equals * or / returns 2.
int rangeOfOperator(char op);

// This function defines operators, calculates the mathematical expression and pushes the result onto the stack for numbers.
bool calculator(std::stack <Lexeme>& stackForNumbers, std::stack <Lexeme>& stackForOperators, Lexeme& item);

// This function calculate mathematical expression and print the result.
void calculateAndPrintResult();

#endif
