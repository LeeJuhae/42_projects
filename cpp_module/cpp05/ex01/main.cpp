/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:40:23 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 10:12:03 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main(void)
{
	Bureaucrat apple("Apple", 2);

	Form form1("form1", 3, 5);
	std::cout << form1 << std::endl;

	apple.signForm(form1);
	apple.signForm(form1);

	try {
		form1.beSigned(apple);
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	apple.decrementGrade();
	apple.decrementGrade();
	std::cout << apple << std::endl;

	try {
		form1.beSigned(apple);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try {
		Form form2("form2", 0, 100);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form form3("form3", 10, 200);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}

