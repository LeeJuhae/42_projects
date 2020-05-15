/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 14:34:29 by ijuhae            #+#    #+#             */
/*   Updated: 2020/05/14 15:06:34 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_info *info, va_list **ap, int *ret)
{
	char	c;

	c = va_arg(**ap, int);
	if (info->flag == ' ')
		*ret += print_blank(1, info->width);
	*ret += write(1, &c, 1);
	if (info->is_left_align)
		*ret += align_left_for_c(info);
}

void	print_percent(t_info *info, int *ret)
{
	char *str;

	str = ft_strdup("%");
	if (!info->is_left_align)
	{
		if (info->flag == '0')
			*ret += print_zero(0, (info->width) - 1);
		else
			*ret += print_blank(0, (info->width) - 1);
	}
	*ret += write(1, str, 1);
	if (info->is_left_align)
		*ret += print_blank(0, (info->width) - 1);
}
