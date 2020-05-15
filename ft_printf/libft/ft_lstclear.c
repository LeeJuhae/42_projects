/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:41:49 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/09 13:49:43 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *old_elem;

	if (lst == 0 || *lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		old_elem = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(old_elem, del);
	}
}
