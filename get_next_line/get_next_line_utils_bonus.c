/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:29:34 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/13 16:38:45 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char			*p;
	unsigned int	idx;

	p = 0;
	idx = 0;
	while (1)
	{
		if (s[idx] == (char)c)
		{
			p = (char *)s + idx;
			break ;
		}
		if (s[idx] == '\0')
			break ;
		idx++;
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(const char *str)
{
	char	*p;
	size_t	idx;
	size_t	str_len;

	idx = 0;
	str_len = 0;
	while (str[str_len] != '\0')
		str_len++;
	p = (char *)malloc(str_len + 1);
	if (p == 0)
		return (0);
	while (idx < str_len)
	{
		p[idx] = str[idx];
		idx++;
	}
	p[idx] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx;
	char	*str;

	idx = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == 0)
		return (0);
	while (*s1 != '\0')
	{
		str[idx] = *s1;
		s1++;
		idx++;
	}
	while (*s2 != '\0')
	{
		str[idx] = *s2;
		s2++;
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	idx;
	void	*p;

	idx = 0;
	p = malloc(count * size);
	if (p == 0)
		return (0);
	while (idx < count)
	{
		((char *)p)[idx] = 0;
		idx++;
	}
	return (p);
}
