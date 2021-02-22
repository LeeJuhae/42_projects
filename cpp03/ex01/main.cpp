/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:07:24 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/21 16:38:51 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"
#include <time.h>

int main(void)
{
	srand(time(NULL));

	FragTrap frag("Frag");
	ScavTrap scav("Scav");

	frag.rangedAttack("Scav");
	scav.takeDamage(20);
	scav.meleeAttack("Frag");
	frag.takeDamage(30);
	frag.beRepaired(100);

	scav.takeDamage(30);
	scav.takeDamage(20);
	scav.takeDamage(17);
	scav.takeDamage(300);
	scav.beRepaired(42);
	std::cout << "-=-=-=-=-RANDOM CHALLENGE-=-=-=-=-" << std::endl;
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	return (0);
}
