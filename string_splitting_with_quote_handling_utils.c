/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_splitting_with_quote_handling_utils.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:35:03 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 13:23:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
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
