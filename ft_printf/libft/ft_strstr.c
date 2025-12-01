/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:10:43 by ttiprez           #+#    #+#             */
/*   Updated: 2025/09/09 15:24:37 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;
	size_t	len_to_find;

	if (!*to_find)
		return ((char *)str);
	len_to_find = ft_strlen(to_find);
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (to_find[j])
		{
			if (str[i + j] != to_find[j])
				break ;
			j++;
		}
		if (j == len_to_find)
			return ((char *)&str[i]);
	}
	return (NULL);
}
