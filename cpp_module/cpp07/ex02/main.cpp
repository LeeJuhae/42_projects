/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:22:28 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/28 15:38:13 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Array.hpp"

int main(void)
{
	int n = 3;
	Array<int>			intArr;
	Array<int>			intArr2(n);
	Array<double>		doubleArr(n);
	Array<std::string>	stringArr(n);

	std::cout << "\033[1;31mTEST - size()\033[0m" << std::endl;
	std::cout << "intArr: " << intArr.size() << std::endl;
	std::cout << "intArr2: " << intArr2.size() << std::endl;
	std::cout << "doubleArr: " << doubleArr.size() << std::endl;
	std::cout << "stringArr: " << stringArr.size() << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-"  << std::endl;

	std::cout << "\033[1;31mTEST - operator[] : out of limits \033[0m" << std::endl;
	try {
		intArr[0] = 0;
		std::cout << intArr[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() <<  std::endl;
	}
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-"  << std::endl;

	std::cout << "\033[1;31mTEST - operator[]\033[0m" << std::endl;
	for (int i = 0 ; i < 3 ; i++)
	{
		intArr2[i] = i + 10;
		doubleArr[i] = i + 0.5;
		stringArr[i] = "42seoul";
	}

	for (int i = 0 ; i < 3 ; i++)
	{
		std::cout << intArr2[i] << std::endl;
		std::cout << doubleArr[i] << std::endl;
		std::cout << stringArr[i] << std::endl << std::endl;
	}
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-"  << std::endl;

	return (0);
}
