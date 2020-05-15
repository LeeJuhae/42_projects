/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:08:07 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/07 11:21:17 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char			*p;
	unsigned int	idx;

	p = 0;
	idx = 0;
	while (1)
	{
		if (s[idx] == (char)c)
			p = (char *)s + idx;
		if (s[idx] == '\0')
			break ;
		idx++;
	}
	return (p);
}
