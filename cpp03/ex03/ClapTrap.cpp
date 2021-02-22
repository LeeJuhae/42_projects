/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:11:40 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/22 17:02:54 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
	hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	level(1),
	name(name),
	melee_attack_damage(100),
	ranged_attack_damage(100),
	armor_damage_reduction(100)
{
	std::cout << "ClapTrap 🤖 Create player [" << name << "]!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy):
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
	std::cout << "ClapTrap 🤖 Create player [" << name << "]!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap&op)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap 💀 [" << this->name << "] Game Over!" << std::endl;
}

void ClapTrap::copy(ClapTrap const &copy)
{
	this->hit_points = copy.hit_points;
	this->max_hit_points = copy.max_hit_points;
	this->energy_points = copy.energy_points;
	this->max_energy_points = copy.max_energy_points;
	this->level = copy.level;
	this->melee_attack_damage = copy.melee_attack_damage;
	this->ranged_attack_damage = copy.ranged_attack_damage;
	this->armor_damage_reduction = copy.armor_damage_reduction;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		std::cout << "👌 " << this->name << " was attacked but not damaged" << std::endl;
	else
	{
		amount -= this->armor_damage_reduction;
		if (amount > this->hit_points)
			amount = this->hit_points;
		this->hit_points -= amount;
		std::cout << "ClapTrap 😡 Take Damage.. " << "	🧪 " << this->name << "'s hp is " << this->hit_points << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount + this->hit_points > this->max_hit_points)
		amount = this->max_hit_points - this->hit_points;
	this->hit_points += amount;
	std::cout << "ClapTrap 💪 " << this->name << " was Repaired" << "	🧪 " << this->name << "'s hp is " << this->hit_points << std::endl;
}

std::string &ClapTrap::getName()
{
	return (this->name);
}
