/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:16:26 by ijuhae            #+#    #+#             */
/*   Updated: 2020/05/05 16:00:05 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	idx;
	char	*substr;
	size_t	s_len;

	idx = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start <= s_len)
	{
		while ((idx < len) && (s[start + idx] != '\0'))
		{
			substr[idx] = s[start + idx];
			idx++;
		}
	}
	substr[idx] = '\0';
	return (substr);
}
