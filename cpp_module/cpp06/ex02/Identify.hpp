/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:56:44 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/28 10:01:42 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <time.h>
# include "./Base.hpp"
# include "./A.hpp"
# include "./B.hpp"
# include "./C.hpp"

Base * generate(void);
void identify_from_pointer(Base * p);
void identify_from_reference( Base & p);

#endif
