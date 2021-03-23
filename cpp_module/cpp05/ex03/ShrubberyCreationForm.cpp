/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:19:44 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 16:55:30 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"

const std::string &ShrubberyCreationForm::form_name = std::string("shrubbery creation");

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	Form(form_name, 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	Form(copy.form_name, copy.getSignGrade(), copy.getExecuteGrade()), target(copy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op)
{
	(void)op;
	return (*this);
}

const char* ShrubberyCreationForm::FileException::what() const throw()
{
	return ("ShrubberyCreationForm Exception: File Error");
};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::string const fileName = (this->target + "_shrubbery");
	std::ofstream outfile(fileName, std::ios::out | std::ios::app);
	if (!outfile.is_open() || outfile.bad())
		throw ShrubberyCreationForm::FileException();

	outfile << "           &&& &&  & &&" << std::endl;
	outfile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	outfile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	outfile << "   &() &\\/&|()|/&\\/ '% & ()" << std::endl;
	outfile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	outfile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	outfile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	outfile << "     &&     \\|||" << std::endl;
	outfile << "             |||" << std::endl;
	outfile << "             |||" << std::endl;
	outfile << "             |||" << std::endl;
	outfile << "       , -=-~  .-^- _" << std::endl;
	outfile << "juhlee        `" << std::endl;
	outfile << "	}" << std::endl;
	outfile.close();
}
