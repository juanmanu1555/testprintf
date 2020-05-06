/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 09:36:20 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/14 11:21:50 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		while (len-- > 0)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
