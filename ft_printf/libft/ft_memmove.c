/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:26:07 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/08 15:46:23 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	idx;

	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		idx = len - 1;
		while (idx >= 0)
		{
			((char *)dst)[idx] = ((char *)src)[idx];
			idx--;
		}
	}
	else
	{
		idx = 0;
		while ((size_t)idx < len)
		{
			((char *)dst)[idx] = ((char *)src)[idx];
			idx++;
		}
	}
	return (dst);
}
