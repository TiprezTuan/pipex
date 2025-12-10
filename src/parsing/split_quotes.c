/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:37:49 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/10 20:11:20 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>

static char	*copy_word_loop(char *s, char *word, int *i)
{
	char	quote;

	if (*s == '\\' && *(s + 1))
	{
		word[(*i)++] = *(++s);
		return (++s);
	}
	if (is_quote(*s))
	{
		quote = *s++;
		while (*s && *s != quote)
		{
			if (*s == '\\' && *(s + 1))
				s++;
			word[(*i)++] = *s++;
		}
		if (*s)
			s++;
		return (s);
	}
	word[(*i)++] = *s;
	return (++s);
}

static char	*copy_word(char *s, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (*s && !(*s == ' ' || *s == '\t') && i < len)
		s = copy_word_loop(s, word, &i);
	word[i] = '\0';
	return (word);
}

static char	*skip_word(char *s)
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
	return (s);
}

/****************************************************************************/
/*	Parse la chaine en conservant les espaces presents dans des guillemets	*/
/****************************************************************************/
char	**ft_split_quotes(char *s)
{
	char	**result;
	int		words;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	words = count_words(s);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		s = skip_spaces(s);
		len = word_len(s);
		result[i] = copy_word(s, len);
		if (!result[i])
			return (free_split(result), NULL);
		s = skip_word(s);
		i++;
	}
	result[i] = NULL;
	return (result);
}
