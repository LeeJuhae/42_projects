/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:28:32 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/23 22:33:09 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "./ISquad.hpp"

class Squad: public ISquad
{
	private:
		int count;
		ISpaceMarine **units;

	public:
		Squad();
		Squad(const Squad &copy);
		Squad &operator=(const Squad &op);
		virtual ~Squad();

		int getCount(void) const;
		ISpaceMarine* getUnit(int idx) const;

		int push(ISpaceMarine *unit);
};

#endif
