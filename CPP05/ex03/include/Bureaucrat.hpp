#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string&, int);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat&);
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm&);
		int executeForm(const AForm&);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Grade to high!";}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Grade to low!";}
		};
};

#endif