/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 23:03:06 by ijuhae            #+#    #+#             */
/*   Updated: 2020/03/03 16:43:08 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*p;

	size = 1;
	p = lst;
	if (p == 0)
		return (0);
	while (p->next != 0)
	{
		size++;
		p = p->next;
	}
	return (size);
}
