#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _sign;
		const int _gradeSign;
		const int _gradeExe;
	protected:
		AForm();
		AForm(const std::string, const int, const int);
		AForm(const AForm&);
	public:
		virtual ~AForm();
		const std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExe() const;
		AForm& operator=(const AForm&);
		bool beSigned(Bureaucrat&);
		void setSign(bool);
		virtual int execute(const Bureaucrat&) const = 0;

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
				virtual const char* what() const throw(){return "Form is not signed";}
		};
};

#endif