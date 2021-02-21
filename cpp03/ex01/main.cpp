/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:07:24 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/08 18:47:54 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

int main(void)
{
	FragTrap a("Apple");
	FragTrap b("Banana");

	a.rangedAttack("Banana");
	b.takeDamage(20);
	b.meleeAttack("Apple");
	a.takeDamage(30);
	a.beRepaired(100);
	std::cout << "-=-=-=-=-RANDOM ATTACK EXECUTE-=-=-=-=-" << std::endl;
	b.takeDamage(a.vaulthunter_dot_exe("Banana"));
	b.takeDamage(a.vaulthunter_dot_exe("Banana"));
	b.takeDamage(a.vaulthunter_dot_exe("Banana"));
	b.takeDamage(a.vaulthunter_dot_exe("Banana"));
	b.takeDamage(a.vaulthunter_dot_exe("Banana"));
	a.takeDamage(b.vaulthunter_dot_exe("Apple"));
	a.takeDamage(b.vaulthunter_dot_exe("Apple"));
	a.takeDamage(b.vaulthunter_dot_exe("Apple"));
	a.beRepaired(11);
	b.beRepaired(42);
	return (0);
}
