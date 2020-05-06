/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 09:52:05 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/08 12:10:01 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == d)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
