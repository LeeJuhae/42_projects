/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:09:15 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 18:35:27 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &);
		FragTrap &operator=(const FragTrap &);
		virtual ~FragTrap();

		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		unsigned int vaulthunter_dot_exe(std::string const & target);
};

#endif
