/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:33:40 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:42:39 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "./AWeapon.hpp"
# include "./Enemy.hpp"

class Character
{
	private:
		Character();

		std::string name;
		int ap;
		AWeapon *weapon;

	public:
		Character(std::string const &name);
		Character(const Character &copy);
		Character &operator=(const Character &op);
		virtual ~Character();

		void recoverAP(void);
		void equip(AWeapon *);
		void attack(Enemy *);

		std::string const &getName(void) const;
		int getAP(void) const;
		AWeapon *getAWeapon(void) const;
};

std::ostream &operator<<(std::ostream &out, const Character &character);

#endif
