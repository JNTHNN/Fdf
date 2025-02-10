/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:06:19 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/16 12:35:57 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <mlx.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;
}	t_point;

typedef struct s_fdf
{
	int					x_axis;
	int					y_axis;
	int					**map;
	int					zoom;
	int					move_x;
	int					move_y;

	void				*mlx_ptr;
	void				*win_ptr;

	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	unsigned int		color;
}	t_fdf;

int		check_file(char *file);

/* MAP */

void	map_init(t_fdf *fdf, char *file, int fd);
int		get_x_axis(char *file);
int		get_y_axis(char *file);
void	fill_matrix(t_fdf *fdf, int x_axis, int y_axis, int fd);

/* DRAW */

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	bresenham(t_point dot, float x1, float y1, t_fdf *fdf);

/* MLX */

void	windows_management(t_fdf *fdf);

/* ERROR */

void	ft_error(t_fdf *fdf, int f);
void	free_nums(char **nums);
void	*ft_free_map(t_fdf *fdf);

#endif