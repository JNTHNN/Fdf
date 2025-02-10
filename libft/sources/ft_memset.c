/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:16:08 by jgasparo          #+#    #+#             */
/*   Updated: 2023/04/13 11:42:52 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*cb;
	unsigned char	uc;

	uc = (unsigned char) c;
	cb = b;
	i = 0;
	while (len > i)
	{
		cb[i] = uc;
		i++;
	}
	return (b);
}
