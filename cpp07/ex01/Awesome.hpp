/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:58:26 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/28 13:58:28 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_HPP
# define AWESOME_HPP

# include <iostream>
# include <string>

class Awesome
{
	public:
		Awesome(): m_n(42) {return ;}
		int	get() const { return (this->m_n); }

	private:
		int	m_n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
	o << rhs.get();
	return (o);
}

template< typename T >
void print( T const & x )
{
	std::cout << x << std::endl;
	return ;
}

#endif
