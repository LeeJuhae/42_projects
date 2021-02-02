/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:39:28 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/03 00:39:11 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./Weapon.hpp"

Weapon::Weapon():
	type()
{}

Weapon::Weapon(std::string type):
	type(type)
{}

const std::string Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
