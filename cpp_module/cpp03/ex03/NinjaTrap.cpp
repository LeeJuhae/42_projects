/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:10:23 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 18:09:02 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name):
	ClapTrap::ClapTrap(name)
{
	this->hit_points = 60;
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 5;
	this->armor_damage_reduction = 0;
	std::cout << "NinjaTrap 🤖 Create player [" << name << "]!" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &copy):
	ClapTrap::ClapTrap(copy.name)
{
	ClapTrap::copy(copy);
	std::cout << "NinjaTrap 🤖 Create player [" << name << "]!" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &op)
{
	if (this == &op)
		return (*this);
	ClapTrap::operator=(op);
	return (*this);
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap 💀 [" << this->name << "] Game Over!" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "NinjaTrap 🗡 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage << " points of damage!" << std::endl;
}

void NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << "NinjaTrap 🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage << " points of damage!" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &trap)
{
	std::cout << this->name << " tries to tickle " << trap.getName()
			<< " but realize he has no feets." << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
	if (this->energy_points >= 20)
	{
		this->energy_points -= 20;
		std::cout << this->name << " try to cut through " << trap.getName()
				<< " and damage him for " << this->ranged_attack_damage << "!" << std::endl;
		trap.takeDamage(this->ranged_attack_damage);
	}
	else
		std::cout << this->name << " is too tired." << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
	if (this->energy_points >= 60)
	{
		this->energy_points -= 60;
		std::cout << this->name << " sense the ClapTrap " << trap.getName()
				<< " but can't see it." << std::endl;
	}
	else
	{
		std::cout << this->name << " finally see the ClapTrap " << trap.getName()
				<< " before falling on the ground." << std::endl;
		this->takeDamage(this->hit_points + this->armor_damage_reduction);
	}
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
	if ((rand() % 2) > 0)
	{
		std::cout << this->name << " throw Ninja star at " << trap.getName()
				<< " and damage him for " << this->ranged_attack_damage << "!" << std::endl;
	}
	else
	{
		std::cout << this->name << " throw Ninja star at " << trap.getName()
				<< " but misses" << std::endl;
	}
}
