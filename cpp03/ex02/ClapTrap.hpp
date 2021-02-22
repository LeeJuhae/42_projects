/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:29:41 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/22 14:21:09 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &);
		virtual ~ClapTrap();
		ClapTrap &operator=(const ClapTrap &);

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		unsigned int hit_points;
		unsigned int max_hit_points;
		unsigned int energy_points;
		unsigned int max_energy_points;
		unsigned int level;
		std::string name;
		unsigned int melee_attack_damage;
		unsigned int ranged_attack_damage;
		unsigned int armor_damage_reduction;

		void copy(ClapTrap const &copy);

};

#endif
