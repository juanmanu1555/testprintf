/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:03:33 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 15:28:18 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *first;
	t_list *list;

	if (!lst)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	first = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		list = list->next;
	}
	return (first);
}
