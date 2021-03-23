/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:37:24 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 19:31:32 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"
#include <sstream>

std::string Brain::identify()
{
	std::stringstream address;
	address << this;
	return (address.str());
}

unsigned int Brain::getCapacity()
{
	return (this->capacity);
}

void Brain::setCapacity(unsigned int capacity)
{
	this->capacity = capacity;
}
