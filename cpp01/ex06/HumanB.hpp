/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 00:31:36 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/03 00:48:06 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "./Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void attack();

		// Getter
		const std::string getName();

		// Setter
		void setWeapon(Weapon &weapon);

	private:
		std::string name;
		Weapon *weapon;
};

#endif
