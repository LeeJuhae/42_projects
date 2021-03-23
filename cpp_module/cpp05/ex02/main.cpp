/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:40:23 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 15:01:02 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat apple("Apple", 3);

	RobotomyRequestForm roboto("R");

	try {
		roboto.execute(apple);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		roboto.beSigned(apple);
		std::cout << roboto << std::endl;
		roboto.execute(apple);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		PresidentialPardonForm presidential("P");

		apple.signForm(presidential);
		presidential.execute(apple);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	ShrubberyCreationForm shrubbery("S");

	apple.signForm(shrubbery);
	try {
		std::cout << shrubbery << std::endl;
		shrubbery.execute(apple);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	apple.executeForm(shrubbery);

	Bureaucrat banana("Banana", 140);
	banana.executeForm(shrubbery);

	return (0);
}

