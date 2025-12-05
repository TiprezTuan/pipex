/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_respected_split_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:55:46 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 04:58:50 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

int	ft_count_words(char *str, char c)
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

char	*ft_strndup(const char *src, unsigned int size)
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

void	free_result(char **result)
{
	int	i;

	i = -1;
	while (result[++i])
		free(result[i]);
	free(result);
}

bool	isquote(char quote, char c, bool check_both)
{
	if (check_both)
		return (c == '\'' || c == '"');
	return ((quote == c) && (c == '\'' || c == '"'));
}

int	get_next_quote_i(char *str, char quote)
{
	int	i;

	i = 0;
	while (str[i] && !isquote(quote, str[i], false))
		i++;
	return (i);
}
