/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:51:08 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/08 19:07:24 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):
	hit_points(100),
	max_hit_points(100),
	energy_points(50),
	max_energy_points(50),
	level(1),
	name(name),
	melee_attack_damage(20),
	ranged_attack_damage(15),
	armor_damage_reduction(3)
{
	std::cout << "🤖 Create player [" << name << "]!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy):
	hit_points(copy.hit_points),
	max_hit_points(copy.max_hit_points),
	energy_points(copy.energy_points),
	max_energy_points(copy.max_energy_points),
	level(copy.level),
	name(copy.name),
	melee_attack_damage(copy.melee_attack_damage),
	ranged_attack_damage(copy.ranged_attack_damage),
	armor_damage_reduction(copy.armor_damage_reduction)
{
	std::cout << "🤖 Create player [" << name << "]!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap&op)
{
	if (this == &op)
		return (*this);
	this->hit_points = op.hit_points;
	this->max_hit_points = op.max_hit_points;
	this->energy_points = op.energy_points;
	this->max_energy_points = op.max_energy_points;
	this->level = op.level;
	this->name = op.name;
	this->melee_attack_damage = op.melee_attack_damage;
	this->ranged_attack_damage = op.ranged_attack_damage;
	this->armor_damage_reduction = op.armor_damage_reduction;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "💀 [" << this->name << "] Game Over!" << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "🗡 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		std::cout << "👌 " << this->name << " was attacked but not damaged" << std::endl;
	else
	{
		amount -= this->armor_damage_reduction;
		if (amount > this->hit_points)
			amount = this->hit_points;
		this->hit_points -= amount;
		std::cout << "🩸 Take Damage.. " << "	🧪 " << this->name << "'s hp is " << this->hit_points << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (amount + this->hit_points > this->max_hit_points)
		amount = this->max_hit_points - this->hit_points;
	this->hit_points += amount;
	std::cout << "💪 " << this->name << " was Repaired " << "	🧪 " << this->name << "'s hp is " << this->hit_points << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const &target)
{
	int num;

	if (this->energy_points < 25)
	{
		std::cout << "🚨 " << this->name << "! You don't have enough energy to attack" << std::endl;
		return ;
	}
	num = rand() % 5;
	if (num == 0)
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage / 2 << " points of damage!" << std::endl;
	else if (num == 1)
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage * 2 << " points of damage!" << std::endl;
	else if (num == 2)
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage + 10 << " points of damage!" << std::endl;
	else if (num == 3)
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage * 3 << " points of damage!" << std::endl;
	else
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage - 15 << " points of damage!" << std::endl;
	this->energy_points -= 25;
}
