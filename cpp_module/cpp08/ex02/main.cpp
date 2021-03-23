/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:06:36 by juhlee            #+#    #+#             */
/*   Updated: 2021/03/02 15:05:26 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mutantstack.hpp"
#include <list>

int main()
{
	std::cout << "\n\t\t\033[1;31m STACK TEST\033[0m" << std::endl;

	MutantStack<int> mstack;

	std::cout << "stack.push(5)" << std::endl;
	mstack.push(5);
	std::cout << "stack.push(17)" << std::endl;
	mstack.push(17);

	std::cout << "stack.top(): " << mstack.top() << std::endl;

	std::cout << "stack.pop()" << std::endl;
	mstack.pop();

	std::cout << "stack.size(): " << mstack.size() << std::endl;

	std::cout << "stack.push(3)" << std::endl;
	mstack.push(3);
	std::cout << "stack.push(5)" << std::endl;
	mstack.push(5);
	std::cout << "stack.push(737)" << std::endl;
	mstack.push(737);
	std::cout << "stack.push(0)" << std::endl;
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "<< print stack >>" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "s.size(): " << s.size() << std::endl;
	std::cout << "s.pop()" << std::endl;
	s.pop();
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << "s.size(): " << s.size() << std::endl;

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;

	std::list<int> mlist;
	std::cout << "mlist.push_back(5)" << std::endl;
	mlist.push_back(5);
	std::cout << "mlist.push_back(17)" << std::endl;
	mlist.push_back(17);
	std::cout << "*mlist.end(): " <<  *(--mlist.end()) << std::endl;
	std::cout << "mlist.pop_back()" << std::endl;
	mlist.pop_back();
	std::cout << "mlist.size(): " << mlist.size() << std::endl;
	std::cout << "mlist.push_back(3)" << std::endl;
	mlist.push_back(3);
	std::cout << "mlist.push_back(5)" << std::endl;
	mlist.push_back(5);
	std::cout << "mlist.push_back(737)" << std::endl;
	mlist.push_back(737);
	std::cout << "mlist.push_back(0)" << std::endl;
	mlist.push_back(0);
	std::cout << "<< print mlist >> " << std::endl;
	for (std::list<int>::iterator it = mlist.begin() ; it != mlist.end() ; it++)
		std::cout << *it << std::endl;
	return 0;
}
