/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:42:28 by jgasparo          #+#    #+#             */
/*   Updated: 2023/04/26 13:57:44 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*from;
	unsigned char	*to;
	size_t			i;

	i = 0;
	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	if (to == from && len == 0)
		return (dst);
	if (to < from)
	{
		while (len--)
		{
			to[i] = from[i];
			i++;
		}
	}
	if (to > from)
		while (len --)
			to[len] = from[len];
	return (dst);
}
