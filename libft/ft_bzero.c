/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:07:56 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/07 11:43:10 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t len)
{
	size_t	idx;
	char	*tmp;

	idx = 0;
	tmp = dest;
	while (idx < len)
	{
		tmp[idx] = 0;
		idx++;
	}
}
