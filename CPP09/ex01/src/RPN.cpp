#include "../include/RPN.hpp"
#include <limits>
#include <string>

RPN::RPN() {};

RPN::RPN(const RPN& copy)
{
	this->m_reserve = copy.m_reserve;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->m_reserve = other.m_reserve;
	return *this;
}

RPN::~RPN() {};

const std::stack<int> RPN::getReserve() const
{
	return this->m_reserve;
}

int RPN::parseInput(std::string input)
{
	for (int index = 0; static_cast<unsigned long>(index) < input.size(); index++)
	{
		if (std::isspace(input[index]))
			continue;
		else if (std::isdigit(input[index]) && !std::isdigit(input[index + 1]))
		{
			this->m_reserve.push(input[index] - '0');
		}
		else if (input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/')
		{
			if (this->m_reserve.size() < 2)
				throw WrongCharacterException();
			int number2 = this->m_reserve.top();
			this->m_reserve.pop();
			int number1 = this->m_reserve.top();
			this->m_reserve.pop();
			this->m_reserve.push(this->doOperation(number1, number2, input[index]));
		}
		else
			throw WrongCharacterException();
	}
	if (this->m_reserve.size() != 1)
		throw WrongCharacterException();
	return this->m_reserve.top();
}

int RPN::doOperation(int number1, int number2, char operation)
{
	int output = 0;
	if (operation == '+')
	{
		if (number2 > 0 && number1 > std::numeric_limits<int>::max() - number2)
			throw OverflowException(); // Positive overflow
		if (number2 < 0 && number1 < std::numeric_limits<int>::min() - number2)
			throw OverflowException(); // Negative overflow
		output = number1 + number2;
	}
	else if (operation == '-')
	{
		if (number2 > 0 && number1 < std::numeric_limits<int>::max() + number2)
			throw OverflowException(); // Negative overflow
		if (number2 < 0 && number1 > std::numeric_limits<int>::min() + number2)
			throw OverflowException(); // Positive overflow
		output = number1 - number2;
	}
	else if (operation == '*')
	{
		if (number1 > 0)
		{
			if (number2 > 0)
			{
				if (number1 > std::numeric_limits<int>::max() / number2)
					throw OverflowException(); // Positive overflow
			}
			else
				if (number2 < std::numeric_limits<int>::min() / number1)
					throw OverflowException(); // Negative overflow
    	} 
		else 
		{
        	if (number2 > 0)
			{
            	if (number1 < std::numeric_limits<int>::min() / number2) 
					throw OverflowException(); // Negative overflow
			}
			else 
				if (number1 != 0 && number2 < std::numeric_limits<int>::max() / number1) 
					throw OverflowException(); // Positive overflow
		}
		output = number1 * number2;
	}
	else if (operation == '/')
	{
		if (number2 == 0)
			throw DevideByZeroException();
		if (number1 == std::numeric_limits<int>::min() && number2 == -1)
			throw OverflowException(); // overflow case for min int
		output = number1 / number2;
	}
	return output;
}
