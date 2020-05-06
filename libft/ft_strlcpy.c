/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:14:39 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 14:33:13 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	if (!src)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (*(src + i) != 0 && i < dstsize - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	dst[i] = 0;
	return (len);
}
