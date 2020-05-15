/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:04:22 by ijuhae            #+#    #+#             */
/*   Updated: 2020/03/02 14:14:44 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t	get_word_count(char const *s, char c)
{
	size_t	cnt;
	size_t	word_len;

	cnt = 0;
	word_len = 0;
	while (1)
	{
		if (*s == c || *s == '\0')
		{
			if (word_len != 0)
			{
				cnt++;
				word_len = 0;
			}
			if (*s == '\0')
				break ;
		}
		else
			word_len++;
		s++;
	}
	return (cnt);
}

static	void	free_mem(char **arr, size_t idx)
{
	size_t	free_idx;

	free_idx = 0;
	while (free_idx < idx)
	{
		free(arr[free_idx]);
		idx++;
	}
}

static	char	**alloc_mem(char const *s, char **arr, char c, size_t word_cnt)
{
	size_t	word_idx;
	size_t	word_len;

	word_idx = 0;
	word_len = 0;
	while (word_idx < word_cnt)
	{
		if ((*s == c || *s == '\0') && (word_len != 0))
		{
			arr[word_idx] = (char *)ft_calloc(sizeof(char), (word_len + 1));
			if (arr[word_idx] == 0)
			{
				free_mem(arr, word_idx);
				return (0);
			}
			if (*s == '\0')
				break ;
			word_idx++;
			word_len = 0;
		}
		else if (*s != c)
			word_len++;
		s++;
	}
	return (arr);
}

static	char	**set_words(char const *s, char **arr, char c, size_t word_cnt)
{
	size_t	word_idx;
	size_t	word_len;

	word_idx = 0;
	word_len = 0;
	while (word_idx < word_cnt)
	{
		if ((*s == c || *s == '\0') && word_len != 0)
		{
			arr[word_idx][word_len] = '\0';
			if (*s == '\0')
				break ;
			word_idx++;
			word_len = 0;
		}
		else if (*s != c)
		{
			arr[word_idx][word_len] = *s;
			word_len++;
		}
		s++;
	}
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	size_t	word_cnt;
	char	**arr;

	while ((*s == c) && (*s != '\0'))
		s++;
	word_cnt = get_word_count(s, c);
	arr = (char **)ft_calloc(sizeof(char *), (word_cnt + 1));
	if (arr == 0)
		return (0);
	arr = alloc_mem(s, arr, c, word_cnt);
	if (arr == 0)
		return (0);
	arr = set_words(s, arr, c, word_cnt);
	arr[word_cnt] = 0;
	return (arr);
}
