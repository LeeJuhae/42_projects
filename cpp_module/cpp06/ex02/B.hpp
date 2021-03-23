/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:26:57 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/27 23:27:18 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

# include "./Base.hpp"

class B: public Base
{
	public:
		B();
		B(const B &copy);
		B &operator=(const B &op);
		virtual ~B();
};

#endif
