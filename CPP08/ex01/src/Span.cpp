#include "../include/Span.hpp"
#include <algorithm>
#include <random>

Span::Span()
{
	this->_numbers = std::vector<int>(0);
	this->_size = 0;
	this->_where = 0;
}

Span::Span(unsigned int size)
{
	this->_numbers = std::vector<int>(size);
	this->_size = size;
	this->_where = 0;
}

Span::Span(const Span& copy)
{
	this->_numbers = copy._numbers;
	this->_size = copy._size;
	this->_where = copy._where;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_numbers[i] = copy._numbers[i];
}
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		if (other._size != 0)
		{
			this->_size = other._size;
			this->_numbers = other._numbers;
			this->_where = other._where;
			for (unsigned int i = 0; i < this->_size; i++)
				this->_numbers[i] = other._numbers[i];
		}
		else
		{
			this->_numbers = std::vector<int>(0);
			this->_size = 0;
			this->_where = 0;
		}
	}
	return *this;
}

Span::~Span() {};

void Span::addNumber(int number)
{
	if (this->_where == this->_size)
		throw TooManyElementsException();
	this->_numbers[this->_where] = number;
	this->_where += 1;
}

void Span::seeder(int start, int end)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(start, end);
	while (this->_where != this->_size)
		this->addNumber(dis(gen));
}

int Span::shortestSpan()
{
	if (this->_size < 2)
		throw TooFewElementsException();
	else if (this->_where < 2)
		throw TooFewElementsException();
	std::vector<int> sortedNumbers(this->_numbers);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int smallest = std::numeric_limits<int>::max();
	for (std::size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int diff = sortedNumbers[i] - sortedNumbers[i -1];
		if (diff < smallest)
			smallest = diff;
	}
	return smallest;
}

int Span::longestSpan()
{
	if (this->_size < 2)
		throw TooFewElementsException();
	else if (this->_where < 2)
		throw TooFewElementsException();
	int minElement = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int maxElement = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	return maxElement - minElement;
}

unsigned int Span::getSize() const
{
	return this->_size;
}

const std::vector<int>& Span::getNumbers() const
{
	return this->_numbers;
}

const char* Span::TooManyElementsException::what() const throw()
{
	return "Too many element to add.";
}

const char* Span::TooFewElementsException::what() const throw()
{
	return "Not enough element to give span";
}