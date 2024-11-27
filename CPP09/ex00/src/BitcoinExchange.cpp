#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cstdlib>


BitcoinExchange::BitcoinExchange()
{
	this->startDateDatabase = 0;
	this->endDateDatabase = 0;
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	this->startDateDatabase = copy.startDateDatabase;
	this->endDateDatabase = copy.endDateDatabase;
	std::map<int, float>::const_iterator it = copy.m_database.begin();
	while (it != copy.m_database.end())
	{
		this->m_database[it->first] = it->second;
		++it;
	}
}

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->startDateDatabase = other.startDateDatabase;
		this->endDateDatabase = other.endDateDatabase;
		std::map<int, float>::const_iterator it = other.m_database.begin();
		while (it != other.m_database.end())
		{
			this->m_database[it->first] = it->second;
			++it;
		}
	}
	return *this;
}

int BitcoinExchange::checkDatabaseFile(std::ifstream& data)
{
	std::string line;
	std::getline(data, line);
	if (line.compare("date,exchange_rate"))
		return 1;
	int linesRead = 0;
	while (std::getline(data, line))
	{
		if (this->checkDateTimeAndParse(line, linesRead))
			return 1;
		++linesRead;
	}
	return 0;
}

int BitcoinExchange::checkInput(std::ifstream& data)
{
	std::string line;
	std::getline(data, line);
	if (line.compare("date | value"))
		return 1;
	while (std::getline(data, line))
	{
		try 
		{
			if (this->parseInput(line))
				throw BadInputException(line);
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Error bad input => " << line << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

// private functions

int BitcoinExchange::strToInt(std::string data, int index, int max, int &output)
{
	while (index < max)
	{
		if (isdigit(data[index]))
		{
			output *= 10;
			output += data[index] - '0';
		}
		else
			return 1;
		++index;
	}
	return 0;
}

int BitcoinExchange::checkDateTimeAndParse(std::string dateTime, int lines)
{
	int year = 0;
	int month = 0;
	int day = 0;
	if (dateTime[4] != '-' && dateTime[7] != '-' && dateTime[10] != ',')
		return 1;
	if (this->strToInt(dateTime, 0, 4, year))
		return 1;
	if (this->strToInt(dateTime, 5, 7, month))
		return 1;
	if (month > 12 || month < 0)
		return 1;
	if (this->strToInt(dateTime, 8, 10, day))
		return 1;
	if (day > 31 || day < 0)
		return 1;
	
	float value = std::atof(dateTime.c_str() + 11);
	int key = year;
	key *= 100;
	key += month;
	key *= 100;
	key += day;
	if (lines == 0)
		this->startDateDatabase = key;
	else
		if (key < this->startDateDatabase)
			this->startDateDatabase = key;
	if (key > this->endDateDatabase)
		this->endDateDatabase = key;
	this->m_database.insert(std::pair<int, float>(key, value));
	return 0;
}

int BitcoinExchange::parseInput(std::string data)
{
	std::size_t size = data.size();
	if (size < 14)
		return 1;
	if (size - 13 > 4)
	{
		std::size_t start = 13;
		std::size_t end = 17;
		std::size_t found = data.find('.', start);
		if (found != std::string::npos && found <= end)
			;
		else
			throw NumberTooLargeException();
	}
	int count= 0;
	for (size_t i = 13; i < data.size(); i++)
	{
		if (data[i] == '.')
			count++;
	}
	if (count > 1)
		throw BadInputException(data);
	if (data[4] != '-' && data[7] != '-' && data[10] != ' ' && data [11] != '|' && data[12] != ' ')
		return 1;
	int year = 0;
	int month = 0;
	int day = 0;
	if (this->strToInt(data, 0, 4, year))
		return 1;
	if (this->strToInt(data, 5, 7, month))
		return 1;
	if (month > 12 || month < 0)
		return 1;
	if (this->strToInt(data, 8, 10, day))
		return 1;
	if (day > 31 || day < 0)
		return 1;
	float value = std::stof(data.substr(13, data.size()));
	if (value < 0.0)
		throw NegativeNumberException();
	if (value > 1000)
		throw NumberTooLargeException();
	int key = year;
	key *= 100;
	key += month;
	key*= 100;
	key += day;
	this->outputConvertion(key, value, data);
	return 0;
}

void BitcoinExchange::outputConvertion(int key, float amound, std::string line)
{
	line.replace(11, 1, "=>");
	std::map<int, float>::const_iterator it = this->m_database.begin();
	if (key < this->startDateDatabase)
		throw BeforeDatabaseException();
	else if (key == this->startDateDatabase)
		std::cout << line << " = " << it->second * amound << std::endl;
	else if (key >= this->endDateDatabase)
	{
		it = this->m_database.end();
		--it;
		std::cout << line << " = " << it->second * amound << std::endl;
	}
	else
	{
		while (it != this->m_database.end() && it->first < key)
			++it;
		if (it->second != amound)
			--it;
		std::cout << line << " = " << it->second * amound << std::endl;
	}
}

const char* BitcoinExchange::NegativeNumberException::what() const throw()
{
	return "Error: not a positive number.";
}

const char* BitcoinExchange::NumberTooLargeException::what() const throw()
{
	return "Error: too large a number.";
}

BitcoinExchange::BadInputException::BadInputException(std::string msg)
{
	std::string error = "Error: bad input => ";
	error.append(msg);
	this->message = error;
}
const char* BitcoinExchange::BadInputException::BadInputException::what() const throw()
{
	return message.c_str();
}
const char* BitcoinExchange::BeforeDatabaseException::what() const throw()
{
	return "Error: date before oldest database record.";
}
