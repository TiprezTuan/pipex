/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:29:11 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/13 13:32:41 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	malloc_and_check(char **str, size_t size)
{
	*str = malloc(size);
	if (!*str)
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		if (malloc_and_check(&str, 1) == 0)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while ((s[start + i]) && (i < len))
		i++;
	if (malloc_and_check(&str, i + 1) == 0)
		return (NULL);
	i = 0;
	while ((s[start + i]) && (i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
