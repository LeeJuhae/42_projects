/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:15:21 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/07 11:41:43 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_digit(int n)
{
	size_t	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char			*ft_itoa(int n)
{
	size_t	digit;
	int		sign;
	char	*str;

	digit = get_digit(n);
	sign = 1;
	str = (char *)ft_calloc((digit + 1), sizeof(char));
	if (str == 0)
		return (0);
	if (n < 0)
		sign = -1;
	while (1)
	{
		str[digit - 1] = (n % 10) * sign + '0';
		n = n / 10 * sign;
		if (sign < 0)
		{
			str[0] = '-';
			sign = 1;
		}
		if (n == 0)
			break ;
		digit--;
	}
	return (str);
}
