/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 01:02:44 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/03 13:35:27 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "❗️The number of arguments is not appropriate❗️" << std::endl;
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
	}
	else
	{
		Sed sed(argv[1], argv[2], argv[3]);
		if (sed.check_validity() != -1)
			sed.replace();
	}
	return (0);
}
