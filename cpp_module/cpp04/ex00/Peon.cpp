/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:35:12 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 23:47:49 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Peon.hpp"

Peon::Peon(std::string name):
	Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &copy):
	Victim(copy.name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon &Peon::operator=(const Peon &op)
{
	this->name = op.name;
	return (*this);
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Peon &peon)
{
	out << "I'm " << peon.getName() << " and I like otters!" << std::endl;
	return (out);
}

void Peon::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a pink pony!" << std::endl;
}

