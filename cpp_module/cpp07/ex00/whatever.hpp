/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 11:16:24 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/28 11:46:07 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T &min(T &a, T &b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

template <typename T>
T &max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
