/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:28:53 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/28 14:04:54 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void print_func (const T &ele)
{
	std::cout << "🐓[ " << ele << " ]" << std::endl;
};

template <typename T>
void iter(T *address, int len, void (*func)(const T &ele))
{
	for (int i = 0 ; i < len ; i++)
	{
		func(address[i]);
	}
};

#endif
