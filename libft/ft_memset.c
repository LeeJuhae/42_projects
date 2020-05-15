/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:15:39 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/07 11:06:55 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			idx;
	unsigned char	*tmp;

	idx = 0;
	tmp = dest;
	while (idx < len)
	{
		tmp[idx] = (unsigned char)c;
		idx++;
	}
	return (tmp);
}
