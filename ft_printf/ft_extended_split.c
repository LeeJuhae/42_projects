/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extended_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:05:29 by ijuhae            #+#    #+#             */
/*   Updated: 2020/05/14 15:04:37 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static	void	get_word_count(char *s, char *seps, t_word_info word, int *cnt)
{
	while (1)
	{
		if (*s == '%')
			word.first_cnt++;
		if ((*s == '%' && !(word.first_cnt % 2))
		|| (is_sep(*s, seps) && word.first_cnt % 2))
		{
			(*cnt)++;
			word.len = 0;
			word.first_cnt = 0;
		}
		else
		{
			if (*s == '\0' || *s == '%')
			{
				if (word.len != 0)
					(*cnt)++;
				if (*s == '\0')
					break ;
				word.len = 0;
			}
			word.len++;
		}
		s++;
	}
}

static	char	**set_mem(char *s, char **arr, char *seps, t_word_info w)
{
	while (1)
	{
		if (*s == '%')
			w.first_cnt++;
		if ((*s == '%' && !(w.first_cnt % 2)) ||
		(is_sep(*s, seps) && w.first_cnt % 2))
		{
			if ((arr = set_word_mem(arr, w.idx++, ++w.len)) == 0)
				return (0);
			w.len = 0;
			w.first_cnt = 0;
		}
		else if (*s == '%' || *s == '\0')
		{
			if (w.len != 0 && ((arr = set_word_mem(arr, w.idx++, w.len)) == 0))
				return (0);
			if (*s == '\0')
				break ;
			w.len = 1;
		}
		else
			w.len++;
		s++;
	}
	return (arr);
}

static	char	**set_words(char *s, char **arr, char *seps, t_word_info word)
{
	while (*s != '\0')
	{
		if (*s == '%')
			word.first_cnt++;
		if ((*s == '%' && !(word.first_cnt % 2))
		|| (is_sep(*s, seps) && word.first_cnt % 2))
		{
			arr[word.idx][word.len] = *s;
			word.idx++;
			word.len = 0;
			word.first_cnt = 0;
		}
		else
		{
			if (*s == '%' && word.len != 0)
			{
				word.idx++;
				word.len = 0;
			}
			arr[word.idx][word.len] = *s;
			word.len++;
		}
		s++;
	}
	return (arr);
}

char			**ft_extended_split(char const *s, char *seps)
{
	int			word_cnt;
	char		**arr;
	t_word_info	word;

	word_cnt = 0;
	init_word_info(&word);
	if (ft_strncmp(s, "", 1) != 0)
		get_word_count((char *)s, seps, word, &word_cnt);
	arr = (char **)ft_calloc(sizeof(char *), (word_cnt + 1));
	if (arr == 0)
		return (0);
	arr = set_mem((char *)s, arr, seps, word);
	if (arr == 0)
		return (0);
	arr = set_words((char *)s, arr, seps, word);
	arr[word_cnt] = 0;
	return (arr);
}
