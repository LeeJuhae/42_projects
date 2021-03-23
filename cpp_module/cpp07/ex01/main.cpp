/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:28:52 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/28 14:05:31 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"
#include "./Awesome.hpp"

int main(void)
{
	std::cout << "-=-=-=-= TEST =-=-=-=-" << std::endl;

	std::string a[5] = {"apple", "banana", "cat", "door", "eagle"};
	iter(a, 5, print_func);
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

	char b[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(b, 5, print_func);

	std::cout << "-=-= Awesome TEST =-=-" << std::endl;
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print);
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
	iter(tab2, 5, print);

	return (0);
}
