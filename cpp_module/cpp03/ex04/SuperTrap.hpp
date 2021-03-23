/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:09:38 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 19:07:03 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "./ClapTrap.hpp"
# include "./NinjaTrap.hpp"

class SuperTrap: public FragTrap, public NinjaTrap
{
	public:
		SuperTrap(std::string name);
		SuperTrap(const SuperTrap &copy);
		SuperTrap &operator=(SuperTrap &op);
		virtual ~SuperTrap();

		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
};

#endif
