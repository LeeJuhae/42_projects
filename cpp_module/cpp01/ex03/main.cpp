/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:50:02 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/20 13:31:24 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./ZombieHorde.hpp"

int main(void)
{
	srand(time(NULL));

	ZombieHorde zombies(10);
	zombies.announce();

	std::cout << std::endl;

	ZombieHorde zombies2(4);
	zombies2.announce();

	std::cout << std::endl;

	ZombieHorde invalid_zombies(-2);
	invalid_zombies.announce();

	return (0);
}
