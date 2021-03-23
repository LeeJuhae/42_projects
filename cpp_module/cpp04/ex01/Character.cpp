/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:33:40 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/23 21:15:13 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"

Character::Character(std::string const &name):
	name(name), ap(40), weapon(NULL) {}

Character::Character(const Character &copy):
	name(copy.name), ap(copy.ap), weapon(copy.weapon) {}

Character &Character::operator=(const Character &op)
{
	this->name = op.name;
	this->ap = op.ap;
	this->weapon = op.weapon;
	return (*this);
}

Character::~Character() {}

void Character::recoverAP(void)
{
	this->ap += 10;
	if (this->ap > 40)
		this->ap = 40;
}

void Character::equip(AWeapon *weapon)
{
	this->weapon = weapon;
}

void Character::attack(Enemy *enemy)
{
	if (!(this->weapon) || !enemy)
		return ;
	if (this->ap < this->weapon->getAPCost())
		return ;
	this->ap -= this->weapon->getAPCost();
	std::cout << this->name << " attacks " << enemy->getType() << " with a " << this->weapon->getName() << std::endl;
	this->weapon->attack();
	enemy->takeDamage(this->weapon->getDamage());
	if (enemy->getHP() == 0)
		delete enemy;
}

std::string const &Character::getName() const
{
	return (this->name);
}

int Character::getAP(void) const
{
	return (this->ap);
}

AWeapon *Character::getAWeapon(void) const
{
	return (this->weapon);
}

std::ostream &operator<<(std::ostream &out, const Character &character)
{
	out << character.getName() << " has " << character.getAP() << " AP and ";
	if (character.getAWeapon())
		out << "wields a " << character.getAWeapon()->getName() << std::endl;
	else
		out << "is unarmed" << std::endl;
	return (out);
}
