/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:15:48 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/07 11:25:25 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		(*(unsigned char *)dest) = ((unsigned char *)src)[idx];
		dest++;
		if (((unsigned char *)src)[idx] == (unsigned char)c)
			return (dest);
		idx++;
	}
	return (0);
}
