/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:46:39 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 16:35:52 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "./Zombie.hpp"
# include <cstdlib>
# include <ctime>

class ZombieEvent
{
	public:
		ZombieEvent();

		void setZombieType(std::string type);
		Zombie *newZombie(std::string name);
		Zombie *randomChump();

	private:
		std::string type;
};

#endif
