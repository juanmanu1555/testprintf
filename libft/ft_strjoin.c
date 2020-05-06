/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:07:16 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/12 10:56:56 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	i;
	size_t	k;
	char	*sjoin;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1) + ft_strlen(s2);
	if (!(sjoin = (char *)malloc(len1 + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		sjoin[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != 0)
	{
		sjoin[i + k] = s2[k];
		k++;
	}
	sjoin[i + k] = 0;
	return (sjoin);
}
