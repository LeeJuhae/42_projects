/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:45:44 by ijuhae            #+#    #+#             */
/*   Updated: 2020/05/14 15:41:23 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "./libft/libft.h"

# define U_BASE "0123456789"
# define LOWER_X_BASE "0123456789abcdef"
# define UPPER_X_BASE "0123456789ABCDEF"

typedef struct	s_info
{
	char	flag;
	int		width;
	int		precision;
	char	format;
	int		blank_after_zero;
	int		zero_after_blank;
	int		is_left_align;
	int		has_dot;
}				t_info;
typedef struct	s_word_info
{
	size_t	len;
	size_t	idx;
	int		first_cnt;
}				t_word_info;

int				ft_printf(const char *fmt, ...);
char			**ft_extended_split(char const *s, char *seps);
int				print(t_info *info, va_list *ap);

void			init_word_info(t_word_info *info);
void			init_info(t_info *info);
int				is_format_specifier(char c);
void			set_width(t_info *info, char *fmt, va_list *ap);
void			set_precision(t_info *info, char *fmt, va_list *ap);
void			set_flag(t_info *info, char *fmt);
void			set_info(t_info *info, char *fmt, va_list *ap);

void			free_mem(char **arr, size_t idx);
char			**set_word_mem(char **arr, size_t word_idx, size_t word_len);

void			print_c(t_info *info, va_list **ap, int *ret);
void			print_percent(t_info *info, int *ret);
void			print_d_i(t_info *info, va_list **ap, int *ret);
void			print_s(t_info *info, va_list **ap, int *ret);
void			print_u(t_info *info, va_list **ap, int *ret);
void			print_x(t_info *info, va_list **ap, int *ret);
void			print_p(t_info *info, va_list **ap, int *ret);

size_t			l_get_digit(long n, int base_num);
size_t			ui_get_digit(unsigned int n, int base_num);
char			*ft_ltoa_base(long n, int base_num);
char			*ft_uitoa_base(unsigned int n, char *base);

int				print_sign(int sign);
void			print_flag(t_info info, char *str, int sign, int *ret);

void			do_zero_flag(t_info info, int sign, int *ret, char *str);
void			do_dash_flag(t_info info, int sign, int *ret, char *str);
void			do_has_dot(t_info info, int sign, int *ret, char *str);
void			do_blank_flag(t_info info, int sign, int *ret, char *str);

int				print_blank(int start_idx, int end_idx);
int				print_zero(int start_idx, int end_idx);
int				align_left(t_info *info, char *str, int sign);
int				align_left_for_c(t_info *info);

#endif
