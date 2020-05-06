/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:35:51 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 14:43:07 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (*needle == 0)
		return ((char *)haystack);
	i = ft_strlen(needle);
	while (*haystack && i <= len--)
	{
		if (!ft_strncmp(((char *)haystack), ((char *)needle), i))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
