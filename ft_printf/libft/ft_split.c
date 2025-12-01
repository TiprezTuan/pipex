/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by username          #+#    #+#             */
/*   Updated: 2025/09/09 16:02:30 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strndup(const char *src, unsigned int size)
{
	size_t	i;
	char	*dup_str;

	dup_str = malloc(size + 1);
	if (!dup_str)
		return (NULL);
	i = -1;
	while (src[++i] && i < size)
		dup_str[i] = src[i];
	dup_str[i] = '\0';
	return (dup_str);
}

static int	extract_word(char **res, char *str, char c, int *end)
{
	int	i;
	int	start;

	start = *end;
	i = start;
	while (str[i] && str[i] != c)
		i++;
	*end = i;
	*res = ft_strndup(str + start, i - start);
	if (!*res)
		return (0);
	return (1);
}

static	void	free_result(char **result)
{
	int	i;

	i = -1;
	while (result[++i])
		free(result[i]);
	free(result);
}

char	**ft_split(char *str, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			if (extract_word(&result[j++], str, c, &i) == 0)
				return (free_result(result), NULL);
	}
	result[j] = NULL;
	return (result);
}
