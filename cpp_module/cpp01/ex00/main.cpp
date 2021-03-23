/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:51:54 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 01:22:06 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap()
{
	std::cout << "🦄 Pony On The Heap!" << std::endl;
	Pony *heap_pony = new Pony("Eden", "5", "Germany", "Purple");
	heap_pony->getPony();
	delete heap_pony;
}

void ponyOnTheHeap_leak()
{
	std::cout << "🦄 Pony On The Heap But Leaks memory!" << std::endl;
	Pony *leak_pony = new Pony("Elyseen", "1", "Korea", "Orange");
	leak_pony->getPony();
}

void ponyOnTheStack()
{
	std::cout << "🦄 Pony On The Stack!" << std::endl;
	Pony stack_pony("Aciel", "3", "Swiss", "Skyblue");
	stack_pony.getPony();
}

int main()
{
	ponyOnTheStack();
	ponyOnTheHeap();
	ponyOnTheHeap_leak();
	return (0);
}
