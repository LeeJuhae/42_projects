/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:26:27 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 09:28:23 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Squad.hpp"
#include "./TacticalMarine.hpp"
#include "./AssaultTerminator.hpp"

int main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	std::cout << "-=-=-=-=-=-=-=-=-=-" << std::endl;

	Squad squad;

	squad.push(new TacticalMarine);
	squad.push(new AssaultTerminator);
	for (int i = 0; i < squad.getCount(); i++)
	{
		squad.getUnit(i)->battleCry();
		squad.getUnit(i)->rangedAttack();
		squad.getUnit(i)->meleeAttack();
	}
	return (0);
}
