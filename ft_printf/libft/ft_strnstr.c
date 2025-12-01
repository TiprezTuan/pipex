/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:10:43 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/10 16:16:27 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if ((!str || !to_find) && (n == 0))
		return (0);
	if (to_find[0] == 0)
		return ((char *)str);
	j = 0;
	i = 0;
	while (str[i] && i < n)
	{
		while (str[i + j] == to_find[j] && str[i + j] && i + j < n)
		{
			j++;
			if (to_find[j] == 0)
				return ((char *)str + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
