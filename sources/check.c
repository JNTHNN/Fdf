/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:06:37 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/16 12:07:19 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	check_file(char *file)
{
	char	*file_extension;

	file_extension = ft_strrchr(file, '.');
	if (file_extension && ft_strlen(file_extension) == 4 && \
	!ft_strncmp(file_extension, ".fdf", 4))
	{
		ft_putendl_fd("File good", 1);
		return (1);
	}
	else
	{
		ft_putendl_fd("Error: Invalid file format. Only .fdf file.", 2);
		return (0);
	}
}
