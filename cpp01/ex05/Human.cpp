/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:39:40 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 19:23:49 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Human.hpp"

std::string Human::identify()
{
	return (this->getBrain().identify());
};

Brain &Human::getBrain()
{
	return (this->brain);
};
