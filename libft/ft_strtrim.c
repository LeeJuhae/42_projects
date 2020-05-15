/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:32:55 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/08 15:40:52 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_len;
	char	*str;

	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	str_len = ft_strlen(s1);
	if (str_len == 0)
		str = ft_calloc(1, 1);
	else
	{
		while (ft_strchr(set, s1[str_len - 1]))
			str_len--;
		str = ft_substr(s1, 0, str_len);
	}
	return (str);
}
