/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:27:26 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/27 23:53:34 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

# include "./Base.hpp"

class C: public Base
{
	public:
		C();
		C(const C &copy);
		C &operator=(const C &op);
		virtual ~C();
};

#endif
