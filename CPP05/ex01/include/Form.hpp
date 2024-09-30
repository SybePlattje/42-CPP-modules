#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _sign;
		const int _gradeSign;
		const int _gradeExe;
	public:
		Form();
		Form(const std::string, const int, const int);
		Form(const Form&);
		~Form();
		const std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExe() const;
		Form& operator=(const Form&);
		bool beSigned(Bureaucrat&);
		void setSign(bool);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw(){return "Grade too high";}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw(){return "Grade too low";}
		};

		class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw (){return "From not signed";}
		};
};

std::ostream& operator<<(std::ostream&, Form&);
#endif