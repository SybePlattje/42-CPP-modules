#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
		*this = other;
	return *this;
}

ScalarConverter::~ScalarConverter() {};

std::string ScalarConverter::convertString(std::string input, std::string specials[6], int toInt)
{
	std::string toChar = "";
	for (int i = 0; i < 6; i++)
	{
		if (input == specials[i])
		{
			toChar = "imposible";
			break;
		}
	}
	if (input.size() == 1 && std::isprint(input[0]) && !isdigit(input[0]))
	{
		toChar = "'";
		toChar += input[0];
		toChar += "'";
	}
	else if (toChar == "" && toInt >= 0 && toInt <= 255 && std::isprint(toInt))
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	}
	else if (toChar == "")
		toChar = "Non displayable";
	return toChar;
}

void ScalarConverter::convert(std::string& input)
{
	std::string specials[6] =
	{
		"+inff", "-inff", "nanf",
		"+inf", "-inf", "nan"
	};

	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		toInt = static_cast<int>(input[0]);
	else
	{
		try 
		{
			toInt = std::stoi(input);
		}
		catch(std::exception& e)
		{
			(void)e;
			toChar = "imposible";
		}
	}
	if (toChar.compare("imposible"))
		toChar = ScalarConverter::convertString(input, specials, toInt);
	if (input[input.length() - 1] == 'f')
	{
		if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
			toFloat = static_cast<float>(input[0]);
		else
			toFloat = std::atof(&input[0]);
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
			toDouble = static_cast<double>(input[0]);
		else
			toDouble = std::atof(&input[0]);
		toFloat = static_cast<float>(toDouble);
	}

	std::cout << "Char: " << toChar << std::endl;

	if (toChar == "imposible")
	{
		std::cout << "Int: imposible" << std::endl;
	}
	else
		std::cout << "Int: " << toInt << std::endl;
	
	if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0)
	{
		std::cout << "Float: " << toFloat << ".0f" << std::endl;
		std::cout << "Double: " << toDouble << ".0" << std::endl;
	}
	else
	{
		std::cout << "Float: " << std::setprecision(std::numeric_limits<float>::digits10) << toFloat << "f" <<std::endl;
		std::cout << "Double: " << std::setprecision(std::numeric_limits<double>::digits10) << toDouble  << std::endl;
	}
}
