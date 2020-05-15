/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:20:19 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/08 15:52:40 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hay_idx;
	int		needle_len;

	hay_idx = 0;
	needle_len = 0;
	while (needle[needle_len] != '\0')
		needle_len++;
	if (needle_len == 0)
		return ((char *)haystack);
	while (hay_idx < len && (hay_idx + needle_len) <= len)
	{
		if (ft_strncmp(haystack + hay_idx, needle, needle_len) == 0)
			return ((char *)haystack + hay_idx);
		hay_idx++;
	}
	return (0);
}
