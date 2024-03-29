/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:36:44 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/21 17:39:16 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap&op);
		~ScavTrap();
		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer();

	private:
		unsigned int hit_points;
		unsigned int max_hit_points;
		unsigned int energy_points;
		unsigned int max_energy_points;
		unsigned int level;
		std::string name;
		unsigned int melee_attack_damage;
		unsigned int ranged_attack_damage;
		unsigned int armor_damage_reduction;
};

#endif
