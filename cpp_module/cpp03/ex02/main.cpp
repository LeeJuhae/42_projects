/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:07:24 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 17:36:22 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

int main(void)
{
	srand(time(NULL));

	FragTrap *frag = new FragTrap("FR4G");
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->meleeAttack("CL4P-TP");
	frag->rangedAttack("CL4P-TP");
	frag->takeDamage(24);
	frag->beRepaired(50);
	frag->takeDamage(42);
	frag->takeDamage(100);
	frag->beRepaired(125);
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	delete frag;

	std::cout << "-=-=-=-=-=-=-=-=-" << std::endl;

	ScavTrap *scav = new ScavTrap("SC4V");
	scav->challengeNewcomer();
	scav->meleeAttack("CL4P-TP");
	scav->rangedAttack("CL4P-TP");
	scav->takeDamage(24);
	scav->beRepaired(50);
	scav->takeDamage(42);
	scav->takeDamage(100);
	scav->beRepaired(125);
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	delete scav;

	return (0);
}
