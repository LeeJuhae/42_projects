/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:01:16 by ijuhae            #+#    #+#             */
/*   Updated: 2020/03/02 15:43:45 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	char			*str;

	idx = 0;
	if (s == 0 || f == 0)
		return (0);
	str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str == 0)
		return (0);
	str = ft_memcpy(str, s, ft_strlen(s));
	while (str[idx] != '\0')
	{
		str[idx] = f(idx, str[idx]);
		idx++;
	}
	return (str);
}
