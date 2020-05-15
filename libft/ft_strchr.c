/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:33:25 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/07 11:20:55 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char			*p;
	unsigned int	idx;

	p = 0;
	idx = 0;
	while (1)
	{
		if (s[idx] == (char)c)
		{
			p = (char *)s + idx;
			break ;
		}
		if (s[idx] == '\0')
			break ;
		idx++;
	}
	return (p);
}
