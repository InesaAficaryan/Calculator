#include <iostream>
#include <stack>

#include "calculator.h"

int rangeOfOperator(char op)
{
	if (op == '+' || op == '-') return 1;
	if (op == '/' || op == '*') return 2;
	return 0;

}

bool calculator(std::stack <Lexeme>& stackForNumbers, std::stack <Lexeme>& stackForOperators, Lexeme& item)
{
	double a;
	double b;
	double result;
	a = stackForNumbers.top().value; 
	stackForNumbers.pop();
	switch (stackForOperators.top().type)
	{
	case '+':
		b = stackForNumbers.top().value;
		stackForNumbers.pop();
		result = a + b;
		item.type = '0';
		item.value = result;
		stackForNumbers.push(item);
		stackForOperators.pop();
		break;

	case '-':
		b = stackForNumbers.top().value;
		stackForNumbers.pop();
		result = b - a;
		item.type = '0';
		item.value = result;
		stackForNumbers.push(item);
		stackForOperators.pop();
		break;

	case '*':
		b = stackForNumbers.top().value;
		stackForNumbers.pop();
		result = a * b;
		item.type = '0';
		item.value = result;
		stackForNumbers.push(item);
		stackForOperators.pop();
		break;
    
	case '/':
		b = stackForNumbers.top().value;
		if (a == 0)
		{
			std::cerr << "\ncannot be divided by 0!\n";
			return false;
		}
		else
		{
			stackForNumbers.pop();
			result = b / a;
			item.type = '0';
			item.value = result;
			stackForNumbers.push(item);
			stackForOperators.pop();
			break;
		}
		

	default:
		std::cerr << "\nEnter the correct operators!\n";
		return false;
		break;
	}
	return true;

}

void calculateAndPrintResult()
{
        char op;
        double value;
        bool flag = 1;
	std::stack<Lexeme> stackForNumbers;
	std::stack<Lexeme> StackForOperators;
	Lexeme item; 
	while (1)
	{
		op = std::cin.peek();
		if (op == '\n')break;
		if (op == ' ')
		{
			std::cin.ignore();
			continue;
		}
		if (op >= '0' && op <= '9' || op == '-' && flag == 1)
		{
			std::cin >> value;
			item.type = '0';
			item.value = value;
			stackForNumbers.push(item);
			flag = 0;
			continue;
		}

		if (op == '+' || op == '-' && flag == 0 || op == '*' || op == '/')
		{
			if (StackForOperators.size() == 0)
			{
				item.type = op;
				item.value = 0;
				StackForOperators.push(item);
				std::cin.ignore();
				continue; 
			}
			
			if (StackForOperators.size() != 0 && rangeOfOperator(op) > rangeOfOperator(StackForOperators.top().type) )
			{
				item.type = op;
				item.value = 0;
				StackForOperators.push(item);
				std::cin.ignore();
				continue;
			}

			if (StackForOperators.size() != 0 && rangeOfOperator(op) <= rangeOfOperator(StackForOperators.top().type))
			{
				if (calculator(stackForNumbers, StackForOperators, item) == false)
					system("pause");
				continue;
			}
		}
		if (op == '(')
		{
			item.type = op;
			item.value = 0;
			StackForOperators.push(item);
			std::cin.ignore();
			continue;
		}
		if (op == ')')
		{
			while (StackForOperators.top().type != '('){
				if (calculator(stackForNumbers, StackForOperators, item) == false)
					system("pause");
				
				else continue;
		    }
			StackForOperators.pop();
			std::cin.ignore();
			continue;
		}
		else
		{
			std::cout << "\nSomething is wrong\n";
			system("pause");
		}
	}
	while (StackForOperators.size() != 0)
	{
		if (calculator(stackForNumbers, StackForOperators, item) == false)
			system("pause");
		else continue;
		
	}

	    std::cout << "The answer is: " << stackForNumbers.top().value << std::endl;
		return;
}
