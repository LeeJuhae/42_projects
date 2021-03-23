/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:46:35 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 17:48:10 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{};

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
};

Zombie *ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(name, this->type));
};

Zombie *ZombieEvent::randomChump()
{
	int idx;
	Zombie *z;

	std::string names[5] = {"Elsa", "Anna", "Olaf", "Kristoff", "Sven"};
	srand(time(NULL));
	idx = rand() % 5;
	z = new Zombie(names[idx], this->type);
	z->announce();
	return (z);
};
