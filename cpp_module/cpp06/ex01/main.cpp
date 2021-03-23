/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:25:07 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/28 10:37:53 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DataStruct.hpp"

int main()
{
	void *raw;
	Data *data;

	raw = serialize();
	data = deserialize(raw);

	std::cout << "data->s1: " << data->s1 << " (24 bytes)" << std::endl;
	std::cout << "data->n:  " << data->n << " (4 bytes)" << std::endl;
	std::cout << "data->s2: " << data->s2 << " (24 bytes)" <<  std::endl;

	return (0);
}
