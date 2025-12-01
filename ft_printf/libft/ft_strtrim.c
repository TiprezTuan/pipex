/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:16:47 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/05 17:13:15 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

int	count_nb_char_trimmed(char const *s1, char const *set)
{
	int	nb_char_trimmed;
	int	i;

	nb_char_trimmed = 0;
	i = -1;
	while (s1[++i])
	{
		if (!is_in_set(s1[i], set))
			break ;
		nb_char_trimmed++;
	}
	i = ft_strlen(s1);
	while (s1[--i])
	{
		if (!is_in_set(s1[i], set))
			break ;
		nb_char_trimmed++;
	}
	return (nb_char_trimmed);
}

int	set_start(char const *s1, char const *set)
{
	int	start;

	start = -1;
	while (s1[++start])
		if (!is_in_set(s1[start], set))
			break ;
	return (start);
}

int	set_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1);
	while (s1[--end])
		if (!is_in_set(s1[end], set))
			break ;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trimmed;
	int		str_trimmed_i;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set || count_nb_char_trimmed(s1, set) == 0)
		return (ft_strdup(s1));
	if ((size_t)count_nb_char_trimmed(s1, set) >= ft_strlen(s1))
		return (ft_strdup(""));
	str_trimmed = malloc(ft_strlen(s1) - count_nb_char_trimmed(s1, set) + 1);
	if (!str_trimmed)
		return (NULL);
	str_trimmed_i = 0;
	start = set_start(s1, set);
	end = set_end(s1, set);
	while (start <= end)
	{
		str_trimmed[str_trimmed_i] = s1[start];
		str_trimmed_i++;
		start++;
	}
	str_trimmed[str_trimmed_i] = 0;
	return (str_trimmed);
}
