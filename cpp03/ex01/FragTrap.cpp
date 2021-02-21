/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:24:35 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/08 18:45:33 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap()
{
	srand(time(NULL));
	std::cout << "🤖 Create player [" << name << "]!" << std::endl;
}

FragTrap::FragTrap(std::string name):
	hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	level(1),
	name(name),
	melee_attack_damage(30),
	ranged_attack_damage(20),
	armor_damage_reduction(5)
{
	srand(time(NULL));
	std::cout << "🤖 Create player [" << name << "]!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy):
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
	srand(time(NULL));
	std::cout << "🤖 Create player [" << name << "]!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap&op)
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

FragTrap::~FragTrap()
{
	std::cout << "💀 [" << this->name << "] Game Over!" << std::endl;
};

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "🗡 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
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

void FragTrap::beRepaired(unsigned int amount)
{
	if (amount + this->hit_points > this->max_hit_points)
		amount = this->max_hit_points - this->hit_points;
	this->hit_points += amount;
	std::cout << "💪 " << this->name << " was Repaired " << "	🧪 " << this->name << "'s hp is " << this->hit_points << std::endl;
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
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage / 2 << " points of damage!" << std::endl;
		damage = this->ranged_attack_damage / 2;
	}
	else if (num == 1)
	{
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage * 2 << " points of damage!" << std::endl;
		damage = this->ranged_attack_damage * 2;
	}
	else if (num == 2)
	{
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at range, causing " << this->ranged_attack_damage + 10 << " points of damage!" << std::endl;
		damage = this->ranged_attack_damage + 10;
	}
	else if (num == 3)
	{
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage * 3 << " points of damage!" << std::endl;
		damage = this->melee_attack_damage * 3;
	}
	else
	{
		std::cout << "🗡 " << this->name <<  " attacks " << target << " at melee, causing " << this->melee_attack_damage - 15 << " points of damage!" << std::endl;
		damage = this->melee_attack_damage - 15;
	}
	this->energy_points -= 25;
	return (damage);
}
