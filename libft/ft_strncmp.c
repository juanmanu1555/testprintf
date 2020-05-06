/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:24:45 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 14:37:52 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (*(s1 + i) || *(s2 + i)))
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
