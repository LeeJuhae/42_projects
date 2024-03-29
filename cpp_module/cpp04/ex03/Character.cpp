/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:09:23 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:21:09 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"

Character::Character(std::string const &name):
	name(name), equipped(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &copy):
	name(copy.name), equipped(0)
{
	for (int i = 0; i < copy.equipped; i++)
		this->equip(copy.inventory[i]->clone());
	for (int i = this->equipped; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < this->equipped; i++)
		delete this->inventory[i];
}

Character &Character::operator=(Character const &op)
{
	this->name = op.name;
	for (int i = 0; i < this->equipped; i++)
		delete this->inventory[i];
	this->equipped = 0;
	for (int i = 0; i < op.equipped; i++)
		this->equip(op.inventory[i]->clone());
	for (int i = this->equipped; i < 4; i++)
		this->inventory[i] = NULL;
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (this->equipped == 4 || m == NULL)
		return ;
	for (int i = 0; i < this->equipped; i++)
		if (this->inventory[i] == m)
			return ;
	this->inventory[this->equipped++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->equipped || this->inventory[idx] == NULL)
		return ;
	if (idx == 3)
		this->inventory[3] = NULL;
	else
	{
		for (int i = idx; i < 3; i++)
		{
			this->inventory[i] = this->inventory[i + 1];
			this->inventory[i + 1] = NULL;
		}
	}
	this->equipped--;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->equipped || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx]->use(target);
}
