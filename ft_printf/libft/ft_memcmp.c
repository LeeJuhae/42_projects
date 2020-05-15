/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:45:23 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/08 17:12:37 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t	idx;

	idx = 0;
	if (len == 0)
		return (0);
	while (1)
	{
		if (((unsigned char *)s1)[idx] != ((unsigned char *)s2)[idx])
			break ;
		if (idx == len - 1)
			break ;
		idx++;
	}
	return (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx]);
}
