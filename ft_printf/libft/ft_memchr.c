/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:33:45 by ijuhae            #+#    #+#             */
/*   Updated: 2020/02/28 14:00:55 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t			idx;
	unsigned char	*tmp;

	idx = 0;
	tmp = (unsigned char *)s;
	while (idx < len)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
		idx++;
	}
	return (0);
}
