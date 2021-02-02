/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:53:32 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 17:47:41 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieEvent.hpp"

int main(void)
{

	ZombieEvent zombie_event;

	Zombie a = Zombie("A", "a");
	a.announce();

	Zombie *b = new Zombie("B", "b");
	b->announce();
	delete b;

	Zombie *c = zombie_event.newZombie("C");
	c->announce();
	delete c;

	zombie_event.setZombieType("d");

	c = zombie_event.newZombie("D");
	c->announce();
	delete c;

	Zombie *e = zombie_event.randomChump();
	delete e;

	return (0);
}
