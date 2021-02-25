/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:41:37 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 15:00:20 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form(const std::string &name, const int signGrade, const int executeGrade):
	name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy):
	name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	if (this->signGrade < 1 || this->executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->signGrade > 150 || this->executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form &Form::operator=(const Form &op)
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

const char* Form::UnsignedFormException::what() const throw()
{
	return "FormException: Unsigned form can not be executed";
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const std::string &Form::getName(void) const
{
	return (this->name);
}

bool Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->executeGrade);
}

void Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > 150)
		throw Form::GradeTooLowException();
	if (!(this->getIsSigned()))
		throw Form::UnsignedFormException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "[" << form.getName() << " => isSigned: " << (form.getIsSigned() ? "Signed" : "Unsigned") << ", sign grade: " << form.getSignGrade()
	<< ", execute Grade: " << form.getExecuteGrade() << "]";
	return (out);
}
