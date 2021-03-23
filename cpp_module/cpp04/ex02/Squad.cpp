/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:39:14 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:03:52 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Squad.hpp"

Squad::Squad():
	count(0), units(NULL) {}

Squad::Squad(const Squad &copy)
{
	this->count = 0;
	this->units = NULL;
	for(int i = 0 ; i < copy.getCount() ; i++)
		this->push(copy.getUnit(i)->clone());
}

Squad &Squad::operator=(const Squad &op)
{
	if (this->units)
	{
		for (int i = 0 ; i < this->count ; i++)
			delete this->units[i];
		delete this->units;
	}
	this->count = 0;
	for(int i = 0 ; i < op.getCount() ; i++)
		this->push(op.getUnit(i)->clone());
	return (*this);
}

Squad::~Squad()
{
	if (this->units)
	{
		for (int i = 0 ; i < this->count ; i++)
			delete this->units[i];
		delete this->units;
	}
}

int Squad::getCount(void) const
{
	return (this->count);
}

ISpaceMarine* Squad::getUnit(int idx) const
{
	if (this->count == 0 || idx < 0 || idx >= this->count)
		return (NULL);
	return (this->units[idx]);
}

int Squad::push(ISpaceMarine *unit)
{
	if (!unit)
		return (this->count);
	if (this->units)
	{
		for (int i = 0 ; i < this->count ; i++)
			if (this->units[i] == unit)
				return (this->count);
		ISpaceMarine **copy = new ISpaceMarine *[this->count + 1];
		for (int i = 0 ; i < this->count ; i++)
			copy[i] = this->units[i];
		delete[] this->units;
		this->units = copy;
		this->units[this->count] = unit;
		this->count++;
	}
	else
	{
		this->units = new ISpaceMarine*[1];
		this->units[0] = unit;
		this->count = 1;
	}
	return (this->count);
}
