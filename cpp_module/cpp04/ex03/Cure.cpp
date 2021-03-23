/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:13:13 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:14:31 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cure.hpp"

Cure::Cure():
	AMateria("cure") {}

Cure::Cure(Cure const &copy):
	AMateria("cure")
{
	this->_xp = copy._xp;
}

Cure::~Cure() {}

Cure &Cure::operator=(Cure const &op)
{
	this->_xp = op._xp;
	return (*this);
}

AMateria *Cure::clone(void) const
{
	Cure *copy = new Cure(*this);
	return (copy);
}

void Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
