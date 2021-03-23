/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:24:16 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 23:31:01 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Victim.hpp"

Victim::Victim(std::string name):
	name(name)
{
	std::cout << "Some random victim called " << this->getName() << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &copy):
	name(copy.name)
{
	std::cout << "Some random victim called " << this->getName() << " just appeared!" << std::endl;
}

Victim &Victim::operator=(const Victim &op)
{
	this->name = op.name;
	return (*this);
}

Victim::~Victim()
{
	std::cout << "Victim " << this->getName() << " just died for no apparent reason!" << std::endl;
}

const std::string &Victim::getName() const
{
	return (this->name);
}

void Victim::setName(std::string name)
{
	this->name = name;
}

void Victim::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Victim &victim)
{
	out << "I'm " << victim.getName() << " and I like otters!" << std::endl;
	return (out);
}
