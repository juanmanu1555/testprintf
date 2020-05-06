/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:08:16 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 12:05:53 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cmem;

	if (!(cmem = malloc(count * size)))
		return (NULL);
	ft_bzero(cmem, count * size);
	return (cmem);
}
