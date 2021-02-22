/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:51:08 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 16:09:29 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):
	ClapTrap::ClapTrap(name)
{
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->melee_attack_damage = 20;
	this->ranged_attack_damage = 15;
	this->armor_damage_reduction = 3;
	std::cout << "ScavTrap 🤖 Create player [" << name << "]!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy):
	ClapTrap::ClapTrap(copy.name)
{
	ClapTrap::copy(copy);
	std::cout << "ScavTrap 🤖 Create player [" << name << "]!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap&op)
{
	if (this == &op)
		return (*this);
	ClapTrap::operator=(op);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap 💀 [" << this->name << "] Game Over!" << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "ScavTrap 🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "ScavTrap 🗡 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::challengeNewcomer()
{
	int num;

	num = rand() % 5;
	std::cout << "ScavTrap 🏋️‍ " << this->name << "!‍‍ 🧟‍RANDOM CHALLENGE TIME‍🧟‍ " << std::endl;
	if (num == 0)
		std::cout << " << Shooting on the spot all day!! >>" << std::endl;
	else if (num == 1)
		std::cout << " << Jump into the battlefield without weapons!! >>" << std::endl;
	else if (num == 2)
		std::cout << " << Shoot me and go~ >>" << std::endl;
	else if (num == 3)
		std::cout << " << Wear an invisibility cloak!! >>" << std::endl;
	else
		std::cout << " << Double your body size!! >>" << std::endl;
}
