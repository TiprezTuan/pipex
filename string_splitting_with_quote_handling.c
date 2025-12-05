/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_splitting_with_quote_handling.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:33:13 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 16:53:11 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

static char	*remove_quotes(char *str)
{
	char	*result;
	char	current_quote;
	int		j;
	int		i;

	result = malloc(ft_strlen(str) + 1);
	i = 0;
	j = 0;
	current_quote = 0;
	while (str[i])
	{
		if (!current_quote && (str[i] == '"' || str[i] == '\''))
			current_quote = str[i];
		else if (current_quote && str[i] == current_quote)
			current_quote = 0;
		else
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

static int	extract_word(char **res, char *str, char c, int *end)
{
	int	i;
	int	start;

	start = *end;
	i = start;
	while (str[i] && str[i] != c)
	{
		if (isquote(0, str[i], true))
			i += get_next_quote_i(&str[i + 1], str[i]) + 1;
		i++;
	}
	*end = i;
	*res = ft_strndup(str + start, i - start);
	if (!res)
		return (0);
	*res = remove_quotes(*res);
	if (!*res)
		return (0);
	return (1);
}

char	**ft_quotes_respected_split(char *str, char c)
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
