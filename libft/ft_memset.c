/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:54:49 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/10 11:47:22 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		d;
	size_t				i;

	d = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*((unsigned char*)(b + i)) = d;
		i++;
	}
	return (b);
}
