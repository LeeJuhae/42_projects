/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:26:51 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 23:33:03 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title):
	name(name), title(title)
{
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &copy):
	name(copy.name), title(copy.title)
{
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &op)
{
	this->name = op.name;
	this->title = op.title;
	return (*this);
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title << ", is dead. Consequences will never be the same!" << std::endl;
}

const std::string &Sorcerer::getName() const
{
	return (this->name);
}

const std::string &Sorcerer::getTitle() const
{
	return (this->title);
}

void Sorcerer::setName(const std::string &name)
{
	this->name = name;
}

void Sorcerer::setTitle(const std::string &title)
{
	this->title = title;
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer)
{
	out << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
	return (out);
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}
