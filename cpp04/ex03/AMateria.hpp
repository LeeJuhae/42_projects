/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:08:55 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:33:09 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
class ICharacter;
# include "./ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
		unsigned int _xp;

	public:
		AMateria(std::string const &type);
		virtual ~AMateria();

		std::string const &getType(void) const;
		unsigned int getXP(void) const;

		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);
};

#endif
