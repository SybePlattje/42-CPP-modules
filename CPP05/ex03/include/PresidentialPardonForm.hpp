#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(const PresidentialPardonForm&);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		void pardon();
		int execute(const Bureaucrat& executor) const;
};

#endif