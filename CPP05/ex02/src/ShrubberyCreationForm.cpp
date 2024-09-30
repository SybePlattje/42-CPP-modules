#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137)
{
	this->target = "target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy)
{
	this->target = copy.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

void ShrubberyCreationForm::createShrubbery()
{
	std::string name = this->target + "_shrubbery";
	std::ofstream file(name);
	std::ofstream& textfile = treeArt(file);
	textfile.close();
}

std::ofstream& ShrubberyCreationForm::treeArt(std::ofstream& file)
{
	file << R"(                                                         .
                                              .         ;  
                 .              .              ;%     ;;   
                   ,           ,                :;%%  %;   
                    :         ;                   :;%;'     .,   
           ,.        %;     %;            ;        %;'    ,;
             ;       ;%;  %%%%;        ,     %;    ;%;    ,%'
              %;       %%%%;%%%%;      ,  ;       %;  ;%;   ,%;' 
               ;%;      %;        ;%;        % ;%;  ,%;'
                `%;.     ;%;     %;'         `;%%;.%;'
                 `:;%.    ;%%. %@;        %; ;@%;%'
                    `:%;.  :;bd%;          %;@%;'
                      `@%:.  :;%.         ;@@%;'   
                        `@%.  `;@%.      ;@@%;         
                          `@%%. `@%%    ;@@%;        
                            ;@%. :@%%  %@@%;       
                              %@bd%%%bd%%:;     
                                #@%%%%%:;;
                                %@@%%%::;
                                %@@@%(o);  . '         
                                %@@@o%;:(.,'         
                            `.. %@@@o%::;         
                               `)@@@o%::;         
                                %@@(o)::;        
                               .%@@@@%::;         
                               ;%@@@@%::;.          
                              ;%@@@@%%:;;;. 
                          ...;%@@@@@%%:;;;;,..          )";
	return file;
}

int ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
	if (!this->getSign())
	{
		throw NotSignedException();
		return 1;
	}
	if (this->getGradeExe() < executor.getGrade())
		throw GradeTooLowException();
	return 0;
}