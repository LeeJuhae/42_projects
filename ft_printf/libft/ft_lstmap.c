/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:56:08 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/08 15:55:51 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;
	t_list	*new;

	head = 0;
	while (lst != 0)
	{
		new = ft_lstnew(f(lst->content));
		if (new == 0)
		{
			while (head != 0)
			{
				del(head->content);
				head = head->next;
			}
			return (0);
		}
		if (head == 0)
			head = new;
		else
			current->next = new;
		current = new;
		lst = lst->next;
	}
	return (head);
}
