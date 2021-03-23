/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:13:35 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/23 21:03:37 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AWeapon.hpp"

AWeapon::AWeapon():
	name(std::string()), apCost(0), damage(0)
{
}

AWeapon::AWeapon(std::string const & name, int apCost, int damage):
	name(name), apCost(apCost), damage(damage)
{
}

AWeapon::AWeapon(const AWeapon &copy):
	name(copy.name), apCost(copy.apCost), damage(copy.damage)
{
}

AWeapon &AWeapon::operator=(const AWeapon &op)
{
	this->name = op.name;
	this->apCost = op.apCost;
	this->damage = op.damage;
	return (*this);
}

AWeapon::~AWeapon()
{
}

std::string const &AWeapon::getName() const
{
	return (this->name);
}

int AWeapon::getAPCost() const
{
	return (this->apCost);
}

int AWeapon::getDamage() const
{
	return (this->damage);
}
