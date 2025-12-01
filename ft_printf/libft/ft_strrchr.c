/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:06:49 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/10 16:05:01 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	size_t	i;

	i = ft_strlen(str) + 1;
	while (--i > 0)
		if (str[i] == (char)searchedChar)
			return ((char *)&str[i]);
	if (str[i] == (char)searchedChar)
		return ((char *)&str[i]);
	return (NULL);
}
