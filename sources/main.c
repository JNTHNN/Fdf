/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:35:19 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/16 12:35:41 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	if (argc == 2)
	{
		if (argv[1] && check_file(argv[1]))
		{
			fd = open(argv[1], O_RDONLY);
			if (fd == -1)
				ft_error(NULL, 0);
			fdf = (t_fdf *)malloc(sizeof(t_fdf));
			if (!fdf)
				ft_error(NULL, 3);
			map_init(fdf, argv[1], fd);
			windows_management(fdf);
		}
		else
			return (1);
		free(fdf->mlx_ptr);
		ft_free_map(fdf);
		free(fdf);
	}
	else
		ft_error(NULL, 5);
}
