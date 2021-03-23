/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:25:14 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/28 13:25:59 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_HPP
# define AWESOME_HPP

class Awesome
{
	public:
		Awesome() : m_n(0){}
		Awesome(int n): m_n(n){}
		bool operator==( Awesome const & rhs ) { return (this->m_n == rhs.m_n); }
		bool operator!=( Awesome const & rhs ) { return (this->m_n != rhs.m_n); }
		bool operator>( Awesome const & rhs ) { return (this->m_n > rhs.m_n); }
		bool operator<( Awesome const & rhs ) { return (this->m_n < rhs.m_n); }
		bool operator>=( Awesome const & rhs ) { return (this->m_n >= rhs.m_n); }
		bool operator<=( Awesome const & rhs ) { return (this->m_n <= rhs.m_n); }
		int  getN() {
			return(m_n);
		}

	private:
		int m_n;
};

#endif
