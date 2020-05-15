/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:12:06 by ijuhae            #+#    #+#             */
/*   Updated: 2020/05/14 21:25:46 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(t_info *info, va_list *ap)
{
	int	ret;

	ret = 0;
	if (info->format == 'c')
		print_c(info, &ap, &ret);
	else if (info->format == 's')
		print_s(info, &ap, &ret);
	else if (info->format == 'p')
		print_p(info, &ap, &ret);
	else if (info->format == 'd' || info->format == 'i')
		print_d_i(info, &ap, &ret);
	else if (info->format == 'u')
		print_u(info, &ap, &ret);
	else if (info->format == 'x' || info->format == 'X')
		print_x(info, &ap, &ret);
	else if (info->format == '%')
		print_percent(info, &ret);
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_info	info;
	char	**arr;
	int		ret;

	arr = ft_extended_split(fmt, "csdiupxX");
	va_start(ap, fmt);
	ret = 0;
	while (*arr != 0)
	{
		init_info(&info);
		set_info(&info, *arr, &ap);
		if (info.format == 0)
		{
			write(1, *arr, ft_strlen(*arr));
			ret += ft_strlen(*arr);
		}
		else
		{
			ret += print(&info, &ap);
		}
		arr++;
	}
	return (ret);
}
