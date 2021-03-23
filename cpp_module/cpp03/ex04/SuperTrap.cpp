/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:51:13 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 21:56:38 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name):
	ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	this->hit_points = this->FragTrap::hit_points;
	this->max_hit_points = this->FragTrap::max_hit_points;
	this->energy_points = this->NinjaTrap::energy_points;
	this->max_energy_points = this->NinjaTrap::max_energy_points;
	this->melee_attack_damage = this->NinjaTrap::melee_attack_damage;
	this->ranged_attack_damage = this->FragTrap::ranged_attack_damage;
	this->armor_damage_reduction = this->FragTrap::armor_damage_reduction;
	std::cout << "SuperTrap 🤖 Create player [" << name << "]!" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &copy):
	ClapTrap(copy.name), FragTrap(name), NinjaTrap(name)
{
	ClapTrap::copy(copy);
	std::cout << "SuperTrap 🤖 Create player [" << name << "]!" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap &op)
{
	if (this == &op)
		return (*this);
	ClapTrap::operator=(op);
	return (*this);
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap 💀 [" << this->name << "] Game Over!" << std::endl;
}

void SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}
