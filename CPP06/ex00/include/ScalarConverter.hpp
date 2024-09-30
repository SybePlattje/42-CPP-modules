#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
#include <limits>

class ScalarConverter
{
	public:
		static void convert(std::string&);
		~ScalarConverter();
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		static std::string convertString(std::string, std::string[6], int);

};

#endif