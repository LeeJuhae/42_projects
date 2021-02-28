/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:26:21 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/27 23:26:23 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

# include "./Base.hpp"

class A: public Base
{
	public:
		A();
		A(const A &copy);
		A &operator=(const A &op);
		virtual ~A();
};

#endif
