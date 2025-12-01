/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:00:50 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/10 16:04:09 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *str, int searchedChar)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)searchedChar)
			return ((char *)&str[i]);
	if (str[i] == (char)searchedChar)
		return ((char *)&str[i]);
	return (NULL);
}
