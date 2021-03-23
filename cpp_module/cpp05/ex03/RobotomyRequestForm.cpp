/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:43:17 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 16:55:51 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RobotomyRequestForm.hpp"

const std::string &RobotomyRequestForm::form_name = std::string("robotmy request");

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	Form(form_name, 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	Form(copy.form_name, copy.getSignGrade(), copy.getExecuteGrade()), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &op)
{
	(void)op;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << "Bzzzz~!~! Zzzz~!~!~ " << std::endl;
	if (rand() % 2)
		std::cout << "😎 " << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "😡 " << this->target << " robotomization is a failure" << std::endl;
}
