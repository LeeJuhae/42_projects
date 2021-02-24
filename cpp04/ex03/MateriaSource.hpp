/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:20:09 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:20:31 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "./IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		int amount;
		AMateria *sources[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		virtual ~MateriaSource();

		MateriaSource &operator=(MateriaSource const &op);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);
};

#endif
