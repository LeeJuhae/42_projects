/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:50:05 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 18:06:21 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "./Zombie.hpp"
# include <climits>

class ZombieHorde
{
	public:
		ZombieHorde(int N);
		void announce();

	private:
		Zombie *zombies;
		int cnt;
};

#endif
