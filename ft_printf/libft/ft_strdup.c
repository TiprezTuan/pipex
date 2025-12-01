/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:20:14 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/04 16:39:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dup_str;

	len = 0;
	while (src[len])
		len++;
	dup_str = malloc(len + 1);
	if (!dup_str)
		return (NULL);
	dup_str[len] = '\0';
	i = -1;
	while (src[++i])
		dup_str[i] = src[i];
	return (dup_str);
}
