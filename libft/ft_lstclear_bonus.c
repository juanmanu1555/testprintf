/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:45:06 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 15:22:53 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *l;

	l = *lst;
	while (l)
	{
		ft_lstdelone(l, del);
		l = l->next;
	}
	*lst = NULL;
}
