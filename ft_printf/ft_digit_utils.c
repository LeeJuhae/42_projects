/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:19:32 by juhlee            #+#    #+#             */
/*   Updated: 2020/05/14 16:03:31 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(int sign)
{
	int	ret;

	ret = 0;
	if (sign == -1)
		ret = write(1, "-", 1);
	return (ret);
}

int	print_blank(int start_idx, int end_idx)
{
	int	idx;
	int	ret;

	idx = 0;
	ret = 0;
	while (idx + start_idx < end_idx)
	{
		ret += write(1, " ", 1);
		idx++;
	}
	return (ret);
}

int	print_zero(int start_idx, int end_idx)
{
	int	idx;
	int	ret;

	idx = 0;
	ret = 0;
	while (idx + start_idx < end_idx)
	{
		ret += write(1, "0", 1);
		idx++;
	}
	return (ret);
}

int	align_left(t_info *info, char *str, int sign)
{
	int len;
	int	ret;

	ret = 0;
	if (ft_strncmp(str, "0", ft_strlen(str)) == 0
			&& info->flag == '.' && info->precision == 0)
		len = 0;
	else if (info->precision < 1 || (int)ft_strlen(str) > info->precision)
		len = (int)ft_strlen(str);
	else
		len = info->precision;
	ret += print_blank(len - sign, info->width);
	return (ret);
}

int	align_left_for_c(t_info *info)
{
	int	ret;

	ret = 0;
	ret += print_blank(1, info->width);
	return (ret);
}
