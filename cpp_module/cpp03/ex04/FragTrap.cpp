/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:24:35 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 16:09:03 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap(std::string name):
	ClapTrap::ClapTrap(name)
{
	this->melee_attack_damage = 30;
	this->ranged_attack_damage = 20;
	this->armor_damage_reduction = 5;
	std::cout << "FragTrap 🤖 Create player [" << name << "]!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy):
	ClapTrap::ClapTrap(copy.name)
{
	ClapTrap::copy(copy);
	std::cout << "FragTrap 🤖 Create player [" << name << "]!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap&op)
{
	if (this == &op)
		return (*this);
	ClapTrap::operator=(op);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap 💀 [" << this->name << "] Game Over!" << std::endl;
};

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FragTrap 🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FragTrap 🗡 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage << " points of damage!" << std::endl;
}

unsigned int FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int num;
	unsigned int damage;

	if (this->energy_points < 25)
	{
		std::cout << "🚨 " << this->name << "! You don't have enough energy to attack" << std::endl;
		return (0);
	}
	num = rand() % 5;

	if (num == 0)
	{
		std::cout << "0🗡0 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage / 2 << " points of damage!" << std::endl;
		damage = this->ranged_attack_damage / 2;
	}
	else if (num == 1)
	{
		std::cout << "1🗡1 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage * 2 << " points of damage!" << std::endl;
		damage = this->ranged_attack_damage * 2;
	}
	else if (num == 2)
	{
		std::cout << "2🗡2 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage + 10 << " points of damage!" << std::endl;
		damage = this->ranged_attack_damage + 10;
	}
	else if (num == 3)
	{
		std::cout << "3🗡3 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage * 3 << " points of damage!" << std::endl;
		damage = this->melee_attack_damage * 3;
	}
	else
	{
		std::cout << "4🗡4 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage - 15 << " points of damage!" << std::endl;
		damage = this->melee_attack_damage - 15;
	}
	this->energy_points -= 25;
	return (damage);
}
