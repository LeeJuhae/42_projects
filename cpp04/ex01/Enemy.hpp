/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:04:34 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 15:41:45 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
	protected:
		Enemy();
		int hp;
		std::string type;

	public:
		Enemy(int hp, std::string const &type);
		Enemy(const Enemy &copy);
		Enemy &operator=(const Enemy &op);
		virtual ~Enemy();
		std::string const &getType(void) const;
		int getHP(void) const;

		virtual void takeDamage(int damage);
};

#endif
