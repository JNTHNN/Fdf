/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:17:28 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/13 08:22:05 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_copy_to_output(char *output, char *buf)
{
	char	*temp;
	char	*res;

	res = 0;
	if (!output && buf)
	{
		res = ft_strdup(buf);
		if (!res)
			return (ft_free_output(&res, 0));
		return (res);
	}
	temp = ft_strdup(output);
	if (!temp)
	{
		ft_free_output(&output, 0);
		return (ft_free_output(&temp, 0));
	}
	ft_free_output(&output, 0);
	res = ft_strjoin(temp, buf);
	if (!res)
		ft_free_output(&res, 0);
	ft_free_output(&temp, 0);
	return (res);
}

static int	ft_have_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_extract_line(char *output)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!output)
		return (ft_free_output(&output, 0));
	while (output[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free_output(&line, 0));
	j = 0;
	while (j < i + 1)
	{
		line[j] = output[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_recreate_output(char *output)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!output)
		return (NULL);
	while (output[i] != '\n')
		i++;
	if (output[i + 1] == '\0')
		return (ft_free_output(&output, 0));
	res = ft_substr(output, i + 1, ft_strlen(output));
	if (!res)
	{
		ft_free_output(&output, 0);
		return (NULL);
	}
	ft_free_output(&output, 0);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	long		ret;
	static char	*output;
	char		*line;

	ret = BUFFER_SIZE;
	output = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_output(&output, 0));
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret <= 0 && !output) || ret == -1)
			return (ft_free_output(&output, 0));
		buf[ret] = '\0';
		output = ft_copy_to_output(output, buf);
		if (ft_have_nl(output))
		{
			line = ft_extract_line(output);
			if (!line)
				return (ft_free_output(&output, 0));
			return (output = ft_recreate_output(output), line);
		}
	}
	return (ft_free_output(&output, 1));
}
