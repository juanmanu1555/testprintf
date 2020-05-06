/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:59:31 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 13:11:27 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (*(s + i) != 0)
	{
		if (*(s + i) == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}
