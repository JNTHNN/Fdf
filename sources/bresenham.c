/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:46:53 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/16 12:07:07 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	iso(float *y, float *x, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

static void	zoom(t_point *dot, float *x1, float *y1, t_fdf *fdf)
{
	dot->x *= fdf->zoom;
	*x1 *= fdf->zoom;
	dot->y *= fdf->zoom;
	*y1 *= fdf->zoom;
}

static unsigned int	colors(float z, float z1, unsigned int color)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	if (z > 0 || z1 > 0)
	{
		red = 255;
		green = (z + z1) * 10;
		blue = 0;
		color = (red << 16) | (green << 8) | blue;
	}
	else if (z < 0 || z1 < 0)
	{
		red = 255 - z;
		green = 255 - z;
		blue = 255;
		color = (red << 16) | (green << 8) | blue;
	}
	return (color);
}

static void	movers(t_point *dot, float *x1, float *y1, t_fdf *fdf)
{
	dot->x += fdf->move_x;
	*x1 += fdf->move_x;
	dot->y += fdf->move_y;
	*y1 += fdf->move_y;
}

void	bresenham(t_point dot, float x1, float y1, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z;
	int		z1;

	z = fdf->map[(int)dot.x][(int)dot.y];
	z1 = fdf->map[(int)x1][(int)y1];
	zoom(&dot, &x1, &y1, fdf);
	iso(&dot.x, &dot.y, z);
	iso(&x1, &y1, z1);
	movers(&dot, &x1, &y1, fdf);
	x_step = x1 - dot.x;
	y_step = y1 - dot.y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(dot.x - x1) || (int)(dot.y - y1))
	{
		my_mlx_pixel_put(fdf, dot.x, dot.y, colors(z, z1, fdf->color));
		dot.x += x_step;
		dot.y += y_step;
		if (dot.x > HEIGHT || dot.y > WIDTH || dot.x < 0 || dot.y < 0)
			break ;
	}
}
