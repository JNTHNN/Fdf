/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:55:01 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/14 14:39:39 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_secure(long long int resu, long long int temp, \
int sign)
{
	if (temp > resu && sign == -1)
		return (0);
	else if (temp > resu && sign == 1)
		return (-1);
	return (resu);
}

static int	ft_sign(char c)
{
	int	sign;

	sign = 1;
	if (c == '-')
		sign = -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	long			i;
	long long int	resu;
	long long int	temp;
	int				sign;

	i = 0;
	sign = 1;
	resu = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = ft_sign(str[i++]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = resu;
		resu = resu * 10 + (str[i++] - '0');
		ft_secure(resu, temp, sign);
	}
	return (resu * sign);
}
