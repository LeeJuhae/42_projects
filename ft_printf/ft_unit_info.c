/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:51:34 by juhlee            #+#    #+#             */
/*   Updated: 2020/05/14 16:00:48 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_format_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	set_width(t_info *info, char *fmt, va_list *ap)
{
	if (ft_strchr(fmt, '*') != 0 && (ft_strchr(fmt, '.') == 0 ||
				ft_strchr(fmt, '*') < ft_strchr(fmt, '.')))
		info->width = va_arg(*ap, int);
	else
	{
		if (info->flag == '0' && fmt[1] == ' ')
		{
			info->blank_after_zero = 1;
			fmt++;
		}
		info->width = ft_atoi(fmt);
	}
	while (*fmt == ' ')
		fmt++;
	if (fmt[0] == '0')
		info->zero_after_blank = 1;
	if (info->width < 0)
	{
		info->flag = '-';
		info->width = info->width * (-1);
	}
}

void	set_precision(t_info *info, char *fmt, va_list *ap)
{
	if (info->has_dot)
	{
		fmt = ft_strnstr(fmt, ".", ft_strlen(fmt));
		fmt++;
		if (ft_strchr(fmt, '*') != 0)
			info->precision = va_arg(*ap, int);
		else
			info->precision = ft_atoi(fmt);
	}
}

void	set_flag(t_info *info, char *fmt)
{
	if (fmt[1] == '-' || fmt[1] == '0' || fmt[1] == '.'
			|| fmt[1] == '*' || fmt[1] == ' ')
		info->flag = fmt[1];
}

void	set_info(t_info *info, char *fmt, va_list *ap)
{
	size_t	len;

	len = ft_strlen(fmt);
	if (*fmt != '%')
		return ;
	if (is_format_specifier(fmt[len - 1]))
		info->format = fmt[len - 1];
	else
		return ;
	fmt[len - 1] = '\0';
	set_flag(info, fmt);
	fmt++;
	if (ft_strchr(fmt, '.') != 0)
		info->has_dot = 1;
	set_width(info, fmt, ap);
	if (info->flag == '-')
		info->is_left_align = 1;
	set_precision(info, fmt, ap);
	if (info->width != 0 && (info->flag == '*' || info->flag == 0))
		info->flag = ' ';
}
