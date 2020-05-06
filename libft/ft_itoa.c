/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:54:52 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/20 15:39:32 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_it(char *s, long n, int i)
{
	s[i] = 0;
	i--;
	while (i >= 0)
	{
		s[i] = (n > 9) ? (n % 10) + '0' : (n + '0');
		n /= 10;
		i--;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		i;
	long	c;
	char	*it;

	sign = (n < 0) ? -1 : 1;
	i = 0;
	c = (long)n * sign;
	while (c > 0)
	{
		c /= 10;
		i++;
	}
	i = (sign == -1) ? i + 1 : i;
	i = (i == 0) ? 1 : i;
	if (!(it = (char *)malloc(i + 1)))
		return (NULL);
	if (sign == -1)
	{
		it[0] = '-';
		fill_it(it + 1, (long)n * sign, i - 1);
	}
	else
		fill_it(it, (long)n * sign, i);
	return (it);
}
