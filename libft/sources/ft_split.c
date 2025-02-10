/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:58:55 by jgasparo          #+#    #+#             */
/*   Updated: 2023/11/13 12:28:24 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (in_word == 0 && s[i] != c)
		{
			in_word = 1;
			count++;
		}
		else if (in_word == 1 && s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_create_word(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_count;
	int		word_len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	word_count = ft_count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (split == NULL || !s)
		return (NULL);
	while (++i < word_count)
	{
		while (s[j] == c)
			j++;
		word_len = ft_word_len(&s[j], c);
		split[i] = ft_create_word(s, j, j + word_len);
		if (split[i] == NULL)
			return (ft_free(split));
		j += word_len;
	}
	split[word_count] = NULL;
	return (split);
}
