/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:25:35 by ijuhae            #+#    #+#             */
/*   Updated: 2020/02/28 14:15:50 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

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
	{
		errno = ENOMEM;
		return (0);
	}
	while (idx < str_len)
	{
		p[idx] = str[idx];
		idx++;
	}
	p[idx] = '\0';
	return (p);
}
