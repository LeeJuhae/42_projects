/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:10:19 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 18:35:31 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "./ClapTrap.hpp"
# include "./FragTrap.hpp"
# include "./ScavTrap.hpp"
# include <iostream>

class NinjaTrap: virtual public ClapTrap
{
	public:
		NinjaTrap(std::string name);
		NinjaTrap(const NinjaTrap &);
		NinjaTrap &operator=(const NinjaTrap &);
		virtual ~NinjaTrap();

		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		void ninjaShoebox(ClapTrap &trap);
		void ninjaShoebox(FragTrap &trap);
		void ninjaShoebox(ScavTrap &trap);
		void ninjaShoebox(NinjaTrap &trap);
};

#endif
