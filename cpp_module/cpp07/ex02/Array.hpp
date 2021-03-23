/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:06:43 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/28 15:39:59 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T *address;
		unsigned int n;

	public:
		Array():
			address(new T[0]), n(0) {};

		Array(unsigned int n):
			address(new T[n]), n(n) {};

		Array(Array const &copy)
		{
			*this = copy;
		}

		~Array()
		{
			if (this->address)
				delete[] this->address;
		};

		Array&operator=(Array const &op)
		{
			if (this != &op)
			{
				T *temp = new T(op.size());
				for (unsigned int i = 0 ; i < op.size() ; i++)
					temp[i] = op.address[i];
				delete []this->address;
				this->address = temp;
				this->n = op.size();
			}
			return (*this);
		};

		T&operator[](unsigned int idx)
		{
			if (idx < 0 || idx >= this->n)
				throw std::exception();
			return (this->address[idx]);
		};

		unsigned int size(void) const
		{
			return (this->n);
		}
};

#endif
