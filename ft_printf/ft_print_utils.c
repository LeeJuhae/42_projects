/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:01:33 by ijuhae            #+#    #+#             */
/*   Updated: 2020/05/14 16:04:08 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d_i(t_info *info, va_list **ap, int *ret)
{
	int		sign;
	char	*str;

	str = ft_ltoa_base(va_arg(**ap, int), 10);
	sign = 0;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	print_flag(*info, str, sign, ret);
	if (!(ft_strncmp(str, "0", ft_strlen(str)) == 0
				&& info->precision == 0 && info->has_dot))
	{
		*ret += write(1, str, ft_strlen(str));
		if (info->is_left_align)
			*ret += align_left(info, str, sign);
	}
}

void	print_s(t_info *info, va_list **ap, int *ret)
{
	char	*s;
	int		print_len;

	s = va_arg(**ap, char *);
	if (s == 0)
		s = ft_strdup("(null)");
	if (info->has_dot && info->precision > 0
			&& info->precision < (int)ft_strlen(s))
		print_len = info->precision;
	else
		print_len = (int)ft_strlen(s);
	if (info->has_dot && info->precision == 0)
	{
		*ret += print_blank(0, info->width);
	}
	else if ((info->has_dot && info->precision > 0) || info->width != 0)
	{
		if (info->is_left_align)
			*ret += write(1, s, print_len);
		*ret += print_blank(print_len, info->width);
		if (!info->is_left_align)
			*ret += write(1, s, print_len);
	}
	else
		*ret += write(1, s, ft_strlen(s));
}

void	print_u(t_info *info, va_list **ap, int *ret)
{
	unsigned int	u;
	char			*str;

	u = va_arg(**ap, unsigned int);
	str = ft_uitoa_base(u, U_BASE);
	print_flag(*info, str, 0, ret);
	if (!(u == 0 && info->has_dot && info->precision == 0))
	{
		*ret += write(1, str, ft_strlen(str));
		if (info->is_left_align)
			*ret += align_left(info, str, 0);
	}
}

void	print_x(t_info *info, va_list **ap, int *ret)
{
	unsigned int	x;
	char			*str;

	x = va_arg(**ap, unsigned int);
	if (info->format == 'x')
		str = ft_uitoa_base(x, LOWER_X_BASE);
	else
		str = ft_uitoa_base(x, UPPER_X_BASE);
	print_flag(*info, str, 0, ret);
	if (!(x == 0 && info->has_dot && info->precision == 0))
	{
		*ret += write(1, str, ft_strlen(str));
		if (info->is_left_align)
			*ret += align_left(info, str, 0);
	}
}

void	print_p(t_info *info, va_list **ap, int *ret)
{
	unsigned long	p;
	char			*str;

	p = va_arg(**ap, unsigned long);
	if (info->has_dot && info->precision == 0)
		str = "0x";
	else
		str = ft_strjoin("0x", ft_ltoa_base(p, 16));
	print_flag(*info, str, 0, ret);
	*ret += write(1, str, ft_strlen(str));
	if (info->is_left_align)
		*ret += align_left(info, str, 0);
}
