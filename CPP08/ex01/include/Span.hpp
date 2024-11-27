#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span
{
	private:
		std::vector<int> _numbers;
		unsigned int _size;
		unsigned int _where;
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& copy);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int number);
		void seeder(int start, int end);
		int shortestSpan();
		int longestSpan();
		unsigned int getSize() const;
		const std::vector<int>& getNumbers() const;

		class TooManyElementsException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class TooFewElementsException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif