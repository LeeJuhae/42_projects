#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

class NotFoundException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("💥 Error: Not Found");
		};
};

template <typename T>
void easyfind(T &container, int n)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundException();
	std::cout << "💡 Element '" << n << "' at position " << distance(container.begin(), it) << std::endl;
}

#endif
