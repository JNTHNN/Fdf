/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:08:50 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/16 12:12:20 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	manage_key(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		ft_free_map(fdf);
		mlx_destroy_image(fdf->mlx_ptr, fdf->img);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		free(fdf->mlx_ptr);
		free(fdf);
		exit(0);
	}
	return (0);
}

static int	close_window(t_fdf *fdf)
{
	ft_free_map(fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf->mlx_ptr);
	free(fdf);
	exit(0);
}

static void	draw(t_fdf *fdf)
{
	t_point	dot;

	dot.x = 0;
	while (dot.x < fdf->x_axis)
	{
		dot.y = 0;
		while (dot.y < fdf->y_axis)
		{
			if (dot.x != fdf->x_axis - 1)
				bresenham(dot, (dot.x + 1), dot.y, fdf);
			if (dot.y != fdf->y_axis - 1)
				bresenham(dot, dot.x, (dot.y + 1), fdf);
			dot.y++;
		}
		dot.x++;
	}
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (x * fdf->line_length + y * (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	windows_management(t_fdf *fdf)
{
	t_point	dot;

	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == NULL)
		ft_error(fdf, 1);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	fdf->img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, \
				&fdf->line_length, &fdf->endian);
	if (fdf->addr == NULL)
		ft_error(fdf, 1);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img, 100, 100);
	mlx_key_hook(fdf->win_ptr, manage_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_window, fdf);
	mlx_loop(fdf->mlx_ptr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf->mlx_ptr);
}
