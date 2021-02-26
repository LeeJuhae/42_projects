/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:16:58 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/26 21:17:52 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

void * serialize(void);
Data * deserialize(void * raw);

#endif
