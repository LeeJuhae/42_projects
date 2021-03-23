/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:27:13 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/23 20:04:03 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle():
	AWeapon("Plasma Rifle", 5, 21)
{}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &copy):
	AWeapon(copy)
{
}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &op)
{
	this->name = op.name;
	this->apCost = op.apCost;
	this->damage = op.damage;
	return (*this);
}

PlasmaRifle::~PlasmaRifle() {}

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
