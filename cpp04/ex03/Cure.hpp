/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:14:41 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:14:58 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "./AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(Cure const &copy);
		virtual ~Cure();

		Cure &operator=(Cure const &op);

		AMateria *clone(void) const;
		void use(ICharacter &target);
};

#endif
