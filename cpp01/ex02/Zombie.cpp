/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:46:26 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 18:21:24 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Zombie.hpp"

Zombie::Zombie()
{
	this->name.clear();
	this->type.clear();
};

Zombie::Zombie(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
}

Zombie::~Zombie()
{
	std::cout << "	💥 Destroy Zombie. Name is [" << this->getName()
	<< "] and type is [" << this->getType() << "]." << std::endl;
}

void Zombie::announce()
{
	std::cout << "😵 <" << this->getName() << " (" << this->getType() << ")> Braiiiiiiinnnssss..." << std::endl;
};

// Getter
const std::string Zombie::getType()
{
	return (this->type);
};
const std::string Zombie::getName()
{
	return (this->name);
};

// Setter
void Zombie::setType(const std::string type)
{
	this->type = type;
};
void Zombie::setName(const std::string name)
{
	this->name = name;
};
