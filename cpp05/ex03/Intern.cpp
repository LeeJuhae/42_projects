/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:10:49 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 16:55:08 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"

static Form*	createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

static Form*	createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static Form*	createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &op)
{
	(void)op;
	return (*this);
}

Form *Intern::makeForm(const std::string &name, const std::string &target)
{
	Form * form;

	t_form_types forms[] =
	{
		{"presidential pardon", &createPresidentialPardonForm},
		{"robotmy request", &createRobotomyRequestForm},
		{"shrubbery creation", &createShrubberyCreationForm}
	};

	form = NULL;
	for (int i = 0 ; i < 3 ; i++)
	{
		if (forms[i].form_name == name)
		{
			form = forms[i].func(target);
			std::cout << "Intern creates " << *form << std::endl;
			return (form);
		}
	}
	std::cout << "Cannot create Intern of the asked form" << std::endl;
	return (form);
}
