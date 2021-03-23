/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataStruct.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:25:04 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/27 23:25:05 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATASTRUCT_HPP
# define DATASTRUCT_HPP

# include <iostream>
# include <time.h>

# define size_string sizeof(std::string)
# define size_int sizeof(int)

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

Data * deserialize(void * raw);
void * serialize(void);

#endif
