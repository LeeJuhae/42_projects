/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:53:42 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/24 15:42:30 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
	protected:
		AWeapon();

		std::string name;
		int apCost;
		int damage;

	public:
		AWeapon(std::string const & name, int apCost, int damage);
		AWeapon(const AWeapon &copy);
		AWeapon &operator=(const AWeapon &op);
		virtual ~AWeapon();

		std::string const &getName(void) const;
		int getAPCost(void) const;
		int getDamage(void) const;

		virtual void attack() const = 0;
};

# endif
