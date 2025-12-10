/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:39:54 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/10 20:11:24 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

char	*skip_spaces(char *s)
{
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	return (s);
}

char	*skip_quote(char *s, char quote)
{
	s++;
	while (*s && *s != quote)
	{
		if (*s == '\\' && *(s + 1))
			s++;
		s++;
	}
	if (*s)
		s++;
	return (s);
}

int	count_words(char *s)
{
	int		count;

	count = 0;
	s = skip_spaces(s);
	while (*s)
	{
		count++;
		if (is_quote(*s))
			s = skip_quote(s, *s);
		else
		{
			while (*s && !(*s == ' ' || *s == '\t'))
			{
				if (*s == '\\' && *(s + 1))
					s += 2;
				else if (is_quote(*s))
					s = skip_quote(s, *s);
				else
					s++;
			}
		}
		s = skip_spaces(s);
	}
	return (count);
}

int	word_len(char *s)
{
	int		len;
	char	quote;

	len = 0;
	while (*s)
		if (*s == '\\' && *(s + 1) && ++len)
			s += 2;
	else if (is_quote(*s))
	{
		quote = *s++;
		while (*s && *s != quote && ++len)
		{
			if (*s == '\\' && *(s + 1))
				s++;
			s++;
		}
		if (*s)
			s++;
	}
	else if (*s == ' ' || *s == '\t')
		break ;
	else if (++len)
		s++;
	return (len);
}
