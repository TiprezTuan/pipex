/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:40:26 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/08 15:34:08 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	size_t	dest_len;

	dest_len = 0;
	i = -1;
	while (dest[++i])
		dest_len++;
	i = -1;
	while (src[++i] && i < nb)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}
