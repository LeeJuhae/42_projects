/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:55:34 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 01:33:35 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void memoryLeak()
{
	std::string *panther = new std::string("String panther");
	std::cout << *panther << std::endl;
	delete panther;
}
