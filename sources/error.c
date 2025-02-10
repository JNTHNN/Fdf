/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:50:51 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/16 12:24:07 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	*ft_free_map(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->map[i] && i < fdf->x_axis)
	{
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
	return (0);
}

void	free_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	ft_error(t_fdf *fdf, int f)
{
	if (f == 0)
		ft_putendl_fd("Error fd", 2);
	if (f == 1)
	{
		ft_putendl_fd("Error MLX", 2);
		free(fdf);
	}
	if (f == 2)
	{
		ft_putendl_fd("Error split", 2);
		if (fdf)
			free(fdf);
	}
	if (f == 3)
	{
		ft_putendl_fd("Error malloc", 2);
		if (fdf->map)
			ft_free_map(fdf);
	}
	if (f == 5)
		ft_putendl_fd("Error invalid arguments : ./fdf <maps.fdf>", 2);
	exit(1);
}
