/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 17:26:29 by ijuhae            #+#    #+#             */
/*   Updated: 2020/05/14 15:03:02 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	l_get_digit(long n, int base_num)
{
	size_t	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n /= base_num;
		digit++;
	}
	return (digit);
}

size_t	ui_get_digit(unsigned int n, int base_num)
{
	size_t	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n /= base_num;
		digit++;
	}
	return (digit);
}

char	*ft_ltoa_base(long n, int base_num)
{
	size_t	digit;
	int		sign;
	char	*str;

	digit = l_get_digit(n, base_num);
	if ((str = (char *)ft_calloc((digit + 1), sizeof(char))) == 0)
		return (0);
	sign = n < 0 ? -1 : 1;
	while (1)
	{
		str[digit - 1] = (n % base_num) * sign + '0';
		if (str[digit - 1] > '9')
			str[digit - 1] += 39;
		n = n / base_num * sign;
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

char	*ft_uitoa_base(unsigned int n, char *base)
{
	size_t	digit;
	int		sign;
	char	*str;

	digit = ui_get_digit(n, ft_strlen(base));
	str = (char *)ft_calloc((digit + 1), sizeof(char));
	if (str == 0)
		return (0);
	sign = n < 0 ? -1 : 1;
	while (1)
	{
		str[digit - 1] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base) * sign;
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
