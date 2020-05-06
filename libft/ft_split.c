/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:32:54 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 14:55:04 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		words_start(const char *s, char c)
{
	size_t	i;
	size_t	w;
	size_t	j;

	if (s[0] == 0)
		return (0);
	i = 0;
	w = 0;
	while (s[i] == c)
		i++;
	j = i;
	while (s[i] != 0)
	{
		if (s[i] == c && s[i - 1] != c)
			w++;
		i++;
	}
	w = (s[i - 1] != c) ? w + 1 : w;
	return (w);
}

char				**ft_split(char const *s, char c)
{
	size_t	k;
	size_t	i;
	size_t	j;
	size_t	w;
	char	**p;

	if (!s)
		return (NULL);
	w = words_start(s, c);
	if (!(p = (char **)malloc((w + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < w)
	{
		while (s[j] == c)
			j++;
		k = j;
		while (s[j] != c && s[j] != 0)
			j++;
		p[i] = ft_substr(s, k, j - k);
		i++;
	}
	p[i] = (char *)0;
	return (p);
}
