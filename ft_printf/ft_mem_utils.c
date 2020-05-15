/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 17:03:47 by ijuhae            #+#    #+#             */
/*   Updated: 2020/05/14 15:05:40 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_mem(char **arr, size_t idx)
{
	size_t	free_idx;

	free_idx = 0;
	while (free_idx < idx)
	{
		free(arr[free_idx]);
		idx++;
	}
}

char	**set_word_mem(char **arr, size_t word_idx, size_t word_len)
{
	arr[word_idx] = (char *)ft_calloc(word_len + 1, sizeof(char));
	if (arr[word_idx] == 0)
	{
		free_mem(arr, word_idx);
		return (0);
	}
	return (arr);
}
