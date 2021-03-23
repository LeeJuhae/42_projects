/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:54:11 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/28 10:24:56 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Identify.hpp"

Base * generate(void)
{
	Base *ptr;

	if (rand() % 3 == 0)
		ptr = new A();
	else if (rand() % 3 == 1)
		ptr = new B();
	else
		ptr = new C();
	return (ptr);
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "C" << std::endl;
	else
		std::cout << "Error: pointer dynamic_cast failed." << std::endl;
}

void identify_from_reference(Base & p)
{
	try {
		Base &tmp = dynamic_cast<A &>(p);
		(void)tmp;
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
		try {
			Base &tmp = dynamic_cast<B &>(p);
			(void)tmp;
			std::cout << "B" << std::endl;
		} catch (std::exception &e) {
			try {
				Base &tmp = dynamic_cast<C &>(p);
				(void)tmp;
				std::cout << "C" << std::endl;
			} catch (std::exception &e) {
			}
		}
	}
}
