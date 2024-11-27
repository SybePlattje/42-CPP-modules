#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <exception>
# include <string>


class RPN
{
	private:
		std::stack<int> m_reserve;
	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);
		~RPN();
		int parseInput(std::string input);
		int doOperation(int number1, int number2, char operation);
		const std::stack<int> getReserve() const;

	class WrongCharacterException: public std::exception
	{
		public:
			virtual const char *what() const throw() {return "The string is incorrectly written!";}
	};

	class DevideByZeroException: public std::exception
	{
		public:
			virtual const char *what() const throw() {return "You treid to devide by zero!";}
	};

	class OverflowException: public std::exception
	{
		public:
			const char *what() const throw() {return "Integer overflow happend!";}
	};
};

#endif