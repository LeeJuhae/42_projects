/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:26:31 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 22:02:25 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade):
	name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy):
	name(copy.name), grade(copy.grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &op)
{
	this->grade = op.grade;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Exception: Grade Too High");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Exception: Grade Too Low");
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	--(this->grade);
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	++(this->grade);
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// void Bureaucrat::signForm(Form const &form) const
// {
// 	if (form.getIsSigned())
// 		std::cout << "<" << *this << "> signs " << form;
// 	else
// 		std::cout << "<" << *this << "> cannot sign <" << form "> because" << "<" <<
// }


std::ostream &operator<<(std::ostream &out, Bureaucrat const &b)
{
	out << "<" << b.getName() << ">, bureaucrat grade <" << b.getGrade() << ">.";
	return (out);
}
