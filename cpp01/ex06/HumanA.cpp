/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:35:44 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/03 00:31:31 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
:
	name(name),
	weapon(weapon)
{}

void HumanA::attack()
{
	std::cout << this->getName() << " attacks with " << this->weapon.getType() << std::endl;
}

const std::string HumanA::getName()
{
	return (this->name);
}

void HumanA::setName(std::string name)
{
	this->name = name;
}
