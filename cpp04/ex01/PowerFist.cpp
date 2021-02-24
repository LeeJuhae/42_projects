/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:58:34 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/23 20:03:52 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PowerFist.hpp"

PowerFist::PowerFist():
	AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(const PowerFist &copy):
	AWeapon(copy) {}

PowerFist &PowerFist::operator=(const PowerFist &op)
{
	this->name = op.name;
	this->apCost = op.apCost;
	this->damage = op.damage;
	return (*this);
}

PowerFist::~PowerFist() {}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
