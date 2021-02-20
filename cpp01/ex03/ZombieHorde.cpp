/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:50:07 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/20 13:33:29 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	int idx;
	std::string names[5] = {"Elsa", "Anna", "Olaf", "Kristoff", "Sven"};

	if (N <= 0 || N > INT_MAX)
	{
		std::cout << "❗️ N is invalid. N value was set to 1." << std::endl;
		N = 1;
	}
	this->cnt = N;

	this->zombies = new Zombie[this->cnt];

	for (int i = 0 ; i < this->cnt ; i++)
	{
		idx = rand() % 5;
		zombies[i].setName(names[idx]);
	}
};

void ZombieHorde::announce()
{
	for(int i = 0 ; i < this->cnt ; i++)
		this->zombies[i].announce();
};
