/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 08:59:59 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 16:17:14 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	len = (size < len) ? size : len;
	if (!(subs = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[i + start];
		i++;
	}
	subs[i] = 0;
	return (subs);
}
