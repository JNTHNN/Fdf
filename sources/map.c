/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:06:28 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/16 12:33:39 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_datacounter(const char *str, char c)
{
	int	i;
	int	data;

	data = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] && str[i + 1] != '\0')
			data++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (data);
}

int	get_x_axis(char *file)
{
	int		fd;
	char	*line;
	int		y_axis;

	y_axis = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		y_axis++;
		free(line);
	}
	close(fd);
	return (y_axis);
}

int	get_y_axis(char *file)
{
	int		fd;
	char	*line;
	int		x_axis;

	x_axis = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	x_axis = ft_datacounter(line, 32);
	free(line);
	close(fd);
	return (x_axis);
}

void	fill_matrix(t_fdf *fdf, int x_axis, int y_axis, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**nums;

	i = 0;
	while (fd > 0 && i < x_axis)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		nums = ft_split(line, ' ');
		if (!nums)
			ft_error(fdf, 2);
		free(line);
		fdf->map[i] = malloc(sizeof(int) * y_axis);
		if (!(fdf->map[i]))
			ft_error(fdf, 3);
		j = -1;
		while (++j < y_axis)
			fdf->map[i][j] = ft_atoi(nums[j]);
		free_nums(nums);
		i++;
	}
	close(fd);
}

void	map_init(t_fdf *fdf, char *file, int fd)
{
	fdf->x_axis = get_x_axis(file);
	fdf->y_axis = get_y_axis(file);
	fdf->map = malloc(sizeof(int **) * fdf->x_axis + 1);
	if (!(fdf->map))
		ft_error(fdf, 2);
	fdf->move_x = (HEIGHT / 5);
	fdf->move_y = (WIDTH / 2.2);
	fdf->zoom = WIDTH / (3 * fdf->y_axis);
	fdf->color = 0xFFFFFF;
	fill_matrix(fdf, fdf->x_axis, fdf->y_axis, fd);
}
