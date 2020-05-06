/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:24:12 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 12:01:13 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long	total;
	int		sign;

	sign = 1;
	total = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		total = total * 10 + (*str - '0');
		str++;
		if ((total * sign) > 2147483647)
			return (-1);
		else if ((total * sign) < -2147483648)
			return (0);
	}
	return ((int)(sign * total));
}
