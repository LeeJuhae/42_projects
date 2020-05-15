/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:30:11 by ijuhae            #+#    #+#             */
/*   Updated: 2020/03/02 18:21:40 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
