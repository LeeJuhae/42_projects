/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:21:31 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/23 20:33:22 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./SuperMutant.hpp"

SuperMutant::SuperMutant():
	Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}
SuperMutant::SuperMutant(const SuperMutant &copy):
	Enemy(copy)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}
SuperMutant &SuperMutant::operator=(const SuperMutant &op)
{
	this->hp = op.hp;
	this->type = op.type;
	return (*this);
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
	Enemy::takeDamage(damage - 3);
}
