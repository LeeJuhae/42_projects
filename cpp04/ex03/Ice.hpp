/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:15:51 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:16:08 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "./AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(Ice const &copy);
		virtual ~Ice();

		Ice &operator=(Ice const &op);

		AMateria *clone(void) const;
		void use(ICharacter &target);
};

#endif
