/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:13:35 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/23 01:23:06 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AWeapon.hpp"

AWeapon::AWeapon():
	name(std::string()), apcost(0), damage(0)
{
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage):
	name(name), apcost(apcost), damage(damage)
{
}

AWeapon::AWeapon(const AWeapon &copy):
	name(copy.name), apcost(copy.apcost), damage(copy.damage)
{
}

AWeapon &AWeapon::operator=(const AWeapon &op)
{
	this->name = op.name;
	this->apcost = op.apcost;
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
	return (this->apcost);
}

int AWeapon::getDamage() const
{
	return (this->damage);
}
