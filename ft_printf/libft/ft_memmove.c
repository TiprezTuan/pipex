/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:52:17 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/04 16:29:36 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *d, const void *s, size_t size)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	if (!d && !s)
		return (NULL);
	dest = d;
	src = s;
	i = -1;
	if (dest <= src)
		while (++i < size)
			dest[i] = src[i];
	else
	{
		i = size + 1;
		while (--i > 0)
			dest[i - 1] = src[i - 1];
	}
	return (dest);
}
