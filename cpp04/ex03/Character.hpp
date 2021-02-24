/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:12:16 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:13:04 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "./ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string name;
		int equipped;
		AMateria *inventory[4];

	public:
		Character(std::string const &name);
		Character(Character const &copy);
		virtual ~Character();

		Character &operator=(Character const &op);

		std::string const &getName(void) const;

		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
