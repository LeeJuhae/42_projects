/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 00:31:38 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/03 00:54:00 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanB.hpp"

HumanB::HumanB(std::string name):
	name(name),
	weapon()
{}

void HumanB::attack()
{
	std::cout << this->getName() << " attacks with " << this->weapon->getType() << std::endl;
}

// Getter
const std::string HumanB::getName()
{
	return (this->name);
}

// Setter
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
