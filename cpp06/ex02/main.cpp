/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:55:37 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/28 10:24:10 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Identify.hpp"

int main()
{
	srand(time(NULL));

	Base *p1;
	std::cout << "[TEST 1]" <<std::endl;
	p1 = generate();
	std::cout << "identify_from_pointer() : ";
	identify_from_pointer(p1);
	std::cout << "identify_from_refrence() : ";
	identify_from_reference(*p1);
	delete p1;


	Base *p2;
	std::cout << "[TEST 2]" <<std::endl;
	p2 = generate();
	std::cout << "identify_from_pointer() : ";
	identify_from_pointer(p2);
	std::cout << "identify_from_refrence() : ";
	identify_from_reference(*p2);
	delete p2;


	Base *p3;
	std::cout << "[TEST 3]" <<std::endl;
	p3 = generate();
	std::cout << "identify_from_pointer() : ";
	identify_from_pointer(p3);
	std::cout << "identify_from_refrence() : ";
	identify_from_reference(*p3);

	delete p3;
	return (0);
}
