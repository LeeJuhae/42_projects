/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:46:28 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 17:18:19 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name, std::string type);
		~Zombie();

		void announce();

		// Getter
		const std::string getType();
		const std::string getName();

		// Setter
		void setType(const std::string type);
		void setName(const std::string name);

	private:
		std::string type;
		std::string name;
};

#endif
