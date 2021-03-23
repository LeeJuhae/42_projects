#include "easyfind.hpp"
#include <list>
#include <vector>

int main()
{
	std::cout << "	🔥 TEST START 🔥" << std::endl;
	std::list<int> l;
	std::vector<int> v;

	for (int i = 0 ; i < 10 ; i++)
	{
		l.push_back(i);
		v.push_back(i * 10);
	}

	std::cout << "list's elements: ";
	for (std::list<int>::iterator it = l.begin() ; it != l.end() ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	try {
		easyfind(l, 0);
		easyfind(l, 3);
		easyfind(l, 100);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "vector's elements: ";
	for (std::vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	try {
		easyfind(v, 10);
		easyfind(v, 20);
		easyfind(v, 50);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
