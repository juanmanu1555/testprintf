/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 10:47:00 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 14:52:25 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*map;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(map = (char *)malloc(len + 1)))
		return (NULL);
	while (i < (unsigned int)len)
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = 0;
	return (map);
}
