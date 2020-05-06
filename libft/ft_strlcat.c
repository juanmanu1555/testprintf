/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:24:27 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 13:34:36 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[j] && j < dstsize)
		j++;
	i = j;
	while (src[j - i] && j + 1 < dstsize)
	{
		dst[j] = src[j - i];
		j++;
	}
	if (i < dstsize)
		dst[j] = 0;
	return (i + ft_strlen(src));
}
