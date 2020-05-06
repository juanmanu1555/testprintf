/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:00:21 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 14:45:19 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] != 0)
	{
		if (!(ft_strchr(set, s1[i])))
			break ;
		i++;
	}
	j = ((int)len - 1 >= 0) ? (len - 1) : 0;
	while (j > 0 && j > i)
	{
		if (!(ft_strchr(set, s1[j])))
			break ;
		j--;
	}
	return (ft_substr(s1, i, j - i + 1));
}
