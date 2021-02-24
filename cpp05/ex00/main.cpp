/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:40:23 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 21:58:53 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main(void)
{
	Bureaucrat apple("Apple", 100);
	std::cout << apple << std::endl;
	apple.incrementGrade();
	std::cout << apple << std::endl;
	apple.decrementGrade();
	std::cout << apple << std::endl;

	try
	{
		Bureaucrat apple("Tom", 0);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat banana("Banana", 1);
		std::cout << banana << std::endl;
		banana.incrementGrade();
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat banana("Jack", 150);
		std::cout << banana << std::endl;
		banana.decrementGrade();
		std::cout << banana << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

