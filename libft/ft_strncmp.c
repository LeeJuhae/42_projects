/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:44:22 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/08 17:19:26 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	idx;

	idx = 0;
	if (len == 0)
		return (0);
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		if ((unsigned char)s1[idx] != (unsigned char)s2[idx] || idx == len - 1)
			break ;
		idx++;
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
