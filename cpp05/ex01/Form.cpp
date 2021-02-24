/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:41:37 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 22:05:42 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form(std::string &name, int const signGrade, int const executeGrade):
	name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::From(Form const &copy)
	name(copy.name), isSignged(copy.isSigend), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	if (this->signGrade < 1 || this->executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->signGrade > 150 || this->executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form &Form::operator=(Form const &op)
{
	this->isSigned = op.isSigned;
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form Exception: Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form Exception: Grade Too Low");
}

void beSigned(Bureaucrat const &bureaucrat)
{

}

std::string const &getName(void)
{
	return (this->name);
}

bool &getIsSigned(void)
{
	return (this->isSigned);
}

int const &getSignGrade(void)
{
	return (this->signGrade);
}

int const &getExecuteGrade(void)
{
	return (this->executeGrade);
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "<" << form.getName() << ">, sign grade <" << form.getSignGrade()
	<< ">, execute Grade <" << form.getExecuteGrade() << ">.";
	return (out);
}
