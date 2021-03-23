/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:15:08 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:24:52 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Ice.hpp"

Ice::Ice():
	AMateria("ice") {}

Ice::Ice(Ice const &copy):
	AMateria("ice")
{
	this->_xp = copy._xp;
}

Ice::~Ice() {}

Ice &Ice::operator=(Ice const &op)
{
	this->_xp = op._xp;
	return (*this);
}

AMateria *Ice::clone(void) const
{
	Ice *copy = new Ice(*this);
	return (copy);
}

void Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
