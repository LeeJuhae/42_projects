/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataStruct.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:25:01 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/28 10:31:24 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DataStruct.hpp"

Data * deserialize(void * raw)
{
	Data *ptr = new Data;

	ptr->s1 = std::string(static_cast<char *>(raw));
	ptr->n = *(reinterpret_cast<int *>(static_cast<char *>(raw) + size_string));
	ptr->s2 = std::string(static_cast<char *>(raw) + size_int + size_string);
	return (ptr);
}

void * serialize(void)
{
	char *raw;

	std::string s1;
	int n;
	std::string s2;

	std::string alphaNumerical = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	raw = new char[size_string + size_int + size_string];
	srand(time(NULL));

	n = rand();
	for (int i = 0 ; i < 8 ; i++)
	{
		s1 += alphaNumerical[rand() % alphaNumerical.length()];
		s2 += alphaNumerical[rand() % alphaNumerical.length()];
	}

	memcpy(raw, &s1, size_string);
	memcpy(raw + size_string, reinterpret_cast<char *>(&n), size_int);
	memcpy(raw + size_int + size_string, &s2, size_string);

	return (raw);
}
