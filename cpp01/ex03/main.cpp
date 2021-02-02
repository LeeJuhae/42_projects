/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:50:02 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 18:31:50 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./ZombieHorde.hpp"

int main(void)
{
	ZombieHorde zombies(10);
	zombies.announce();

	std::cout << std::endl;
	ZombieHorde invalid_zombies(-2);
	invalid_zombies.announce();

	return (0);
}
