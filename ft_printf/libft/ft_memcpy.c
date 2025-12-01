/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:38:10 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/08 15:30:02 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	if (!d && !s)
		return (NULL);
	dest = d;
	src = s;
	i = -1;
	while (++i < n)
		dest[i] = src[i];
	return (dest);
}
