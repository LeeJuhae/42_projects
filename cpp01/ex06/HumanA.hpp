/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:40:29 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/03 00:30:41 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "./Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);

		void attack();

		// Getter
		const std::string getName();

		// Setter
		void setName(std::string name);

	private:
		std::string name;
		Weapon &weapon;
};

#endif
