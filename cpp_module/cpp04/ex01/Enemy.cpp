/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:04:35 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/23 21:02:22 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Enemy.hpp"

Enemy::Enemy():
	hp(0), type(std::string()) {}

Enemy::Enemy(int hp, std::string const &type):
	hp(hp), type(type) {}

Enemy::Enemy(const Enemy &copy):
	hp(copy.hp), type(copy.type) {}

Enemy &Enemy::operator=(const Enemy &op)
{
	this->hp = op.hp;
	this->type = op.type;
	return (*this);
}

Enemy::~Enemy() {}

std::string const &Enemy::getType(void) const
{
	return (this->type);
}

int Enemy::getHP(void) const
{
	return (this->hp);
}

void Enemy::takeDamage(int damage)
{
	if (damage >= 0)
		this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;
}
