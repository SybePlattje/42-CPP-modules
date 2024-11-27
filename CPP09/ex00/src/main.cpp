#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Not the right amound of arguments!" << std::endl;
		return 1;
	}
	const char *db_name = "data.csv";
	std::ifstream database(db_name);
	if (!database.is_open())
	{
		std::cerr << "Error opening file: " << db_name << std::endl;
		return 1;
	}
	std::ifstream transactions(argv[1]);
	if (!transactions.is_open())
	{
		std::cerr << "Error cant open given file: " << argv[1] << std::endl;
		return 1;
	}
	BitcoinExchange exchange;
	if (exchange.checkDatabaseFile(database))
	{
		std::cerr << "Error parsing database" << std::endl;
		return 1;
	}
	if (exchange.checkInput(transactions))
		return 1;
}
