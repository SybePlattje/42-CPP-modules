#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <exception>


class BitcoinExchange
{
	private:
		std::map<int, float> m_database;
		int startDateDatabase;
		int endDateDatabase;
		int checkDateTimeAndParse(std::string dataTime, int lines);
		int strToInt(std::string data, int index, int max, int& output);
		int parseInput(std::string data);
		void outputConvertion(int key, float amound, std::string line);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		int checkDatabaseFile(std::ifstream& data);
		int checkInput(std::ifstream& data);

		class NegativeNumberException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NumberTooLargeException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class BadInputException: public std::exception
		{
			private:
				std::string message;
			public:
				BadInputException(std::string msg);
				virtual const char *what() const throw();
		};

		class BeforeDatabaseException: public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif