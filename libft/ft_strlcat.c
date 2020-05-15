/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:28:30 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/08 18:52:22 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	ret;
	size_t	dest_idx;
	size_t	src_idx;

	dest_idx = ft_strlen(dest);
	src_idx = 0;
	if (dstsize >= ft_strlen(dest))
		ret = ft_strlen(dest) + ft_strlen(src);
	else
		ret = ft_strlen(src) + dstsize;
	while ((dest_idx + 1 < dstsize) && (src[src_idx] != '\0'))
	{
		dest[dest_idx] = src[src_idx];
		dest_idx++;
		src_idx++;
	}
	dest[dest_idx] = '\0';
	return (ret);
}
