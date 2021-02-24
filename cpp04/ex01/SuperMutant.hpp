/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:19:54 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/23 20:59:52 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "./Enemy.hpp"
# include <iostream>

class SuperMutant: public Enemy
{
	public:
		SuperMutant();
		SuperMutant(const SuperMutant &copy);
		SuperMutant &operator=(const SuperMutant &op);
		virtual ~SuperMutant();

		void takeDamage(int damage);
};

#endif
