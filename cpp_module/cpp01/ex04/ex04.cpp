/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:32:30 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 18:36:31 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *p_str = &str;
	std::string& ref_str = str;

	std::cout << "Using pointer >> " << *p_str << std::endl;
	std::cout << "Using refrence >> " << ref_str << std::endl;

	return (0);
}
