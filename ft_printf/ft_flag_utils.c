/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:14:53 by juhlee            #+#    #+#             */
/*   Updated: 2020/05/14 15:00:05 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_zero_flag(t_info info, int sign, int *ret, char *str)
{
	int print_len;

	if (ft_strncmp(str, "0", ft_strlen(str)) == 0
			&& info.has_dot && info.precision == 0)
		print_len = 0;
	else if (info.width > info.precision
			&& info.precision >= (int)ft_strlen(str))
		print_len = info.precision;
	else
		print_len = (int)ft_strlen(str);
	if (info.width > info.precision
			&& info.has_dot && info.precision >= 0)
		*ret += print_blank(print_len - sign, info.width);
	*ret += print_sign(sign);
	if (info.precision >= info.width || (info.precision == 0 && info.has_dot))
		*ret += print_zero(print_len, info.precision);
	else if (info.precision > 0)
		*ret += print_zero((int)ft_strlen(str), info.precision);
	else
		*ret += print_zero(print_len - sign, info.width);
}

void	do_dash_flag(t_info info, int sign, int *ret, char *str)
{
	if (ft_strncmp(str, "0", ft_strlen(str)) == 0
			&& info.has_dot && info.precision == 0)
		*ret += print_blank(0, info.width);
	else
		*ret += print_sign(sign);
	*ret += print_zero((int)ft_strlen(str), info.precision);
}

void	do_has_dot(t_info info, int sign, int *ret, char *str)
{
	int	idx;
	int	len;

	idx = 0;
	*ret += print_sign(sign);
	if (info.width != 0)
	{
		if (ft_strncmp(str, "0", ft_strlen(str)) == 0 && info.precision < 1)
			len = 0;
		else
			len = (int)ft_strlen(str);
		*ret += print_zero(len, info.precision);
		while (idx + len < info.width)
		{
			if (idx + info.precision < info.width)
				*ret += write(1, " ", 1);
			else
				*ret += write(1, "0", 1);
			idx++;
		}
	}
	else
	{
		*ret += print_zero((int)ft_strlen(str), info.precision);
	}
}

void	do_blank_flag(t_info info, int sign, int *ret, char *str)
{
	int print_len;

	if ((info.width == 0 || info.zero_after_blank) && sign != -1)
		*ret += write(1, " ", 1);
	if (ft_strncmp(str, "0", ft_strlen(str)) == 0
			&& info.has_dot && info.precision == 0)
		print_len = 0;
	else if ((int)ft_strlen(str) - sign <= info.precision)
		print_len = info.precision;
	else
		print_len = (int)ft_strlen(str);
	*ret += print_blank(print_len - sign, info.width);
	*ret += print_sign(sign);
	*ret += print_zero((int)ft_strlen(str), info.precision);
}

void	print_flag(t_info info, char *str, int sign, int *ret)
{
	if (info.flag == '0')
	{
		do_zero_flag(info, sign, ret, str);
	}
	else if (info.flag == '-')
	{
		do_dash_flag(info, sign, ret, str);
	}
	else if (info.flag == ' ')
	{
		do_blank_flag(info, sign, ret, str);
	}
	else if (info.has_dot)
	{
		do_has_dot(info, sign, ret, str);
	}
	else
	{
		*ret += print_sign(sign);
	}
}
