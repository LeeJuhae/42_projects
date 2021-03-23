/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:51:52 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 01:20:51 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony()
{
	this->name.clear();
	this->age.clear();
	this->place_of_birth.clear();
	this->fur_color.clear();
}

Pony::Pony(std::string name, std::string age, std::string place_of_birth, std::string fur_color)
{
	this->name = name;
	this->age = age;
	this->place_of_birth = place_of_birth;
	this->fur_color = fur_color;
}

Pony::~Pony()
{
	std::cout << "💥 Destructor Called." << std::endl;
}

void Pony::getPony()
{
	std::cout << "	Pony's name: " << this->getName() << std::endl;
	std::cout << "	Pony's age: " << this->getAge() << std::endl;
	std::cout << "	Pony's place of birth: " << this->getPlaceOfBirth() << std::endl;
	std::cout << "	Pony's fur color: " << this->getFurColor() << std::endl;
}

// Getter
std::string Pony::getName()
{
	return (this->name);
};

std::string Pony::getAge()
{
	return (this->age);
};

std::string Pony::getPlaceOfBirth()
{
	return (this->place_of_birth);
};

std::string Pony::getFurColor()
{
	return (this->fur_color);
};

// Setter
void Pony::setName(std::string name)
{
	this->name = name;
};

void Pony::setAge(std::string age)
{
	this->age = age;
};

void Pony::setPalceOfBirth(std::string place_of_birth)
{
	this->place_of_birth = place_of_birth;
};

void Pony::setFurColor(std::string fur_color)
{
	this->fur_color = fur_color;
};
