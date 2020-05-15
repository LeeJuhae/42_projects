/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_info_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:51:42 by ijuhae            #+#    #+#             */
/*   Updated: 2020/05/14 15:44:18 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_word_info(t_word_info *info)
{
	info->len = 0;
	info->idx = 0;
	info->first_cnt = 0;
}

void	init_info(t_info *info)
{
	info->flag = 0;
	info->width = 0;
	info->precision = 0;
	info->format = 0;
	info->blank_after_zero = 0;
	info->zero_after_blank = 0;
	info->is_left_align = 0;
	info->has_dot = 0;
}
