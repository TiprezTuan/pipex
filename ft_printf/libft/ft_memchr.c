/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:55:15 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/04 16:31:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	const unsigned char	*p;
	size_t				i;

	p = memoryBlock;
	i = -1;
	while (++i < size)
		if (p[i] == (unsigned char)searchedChar)
			return ((void *)&p[i]);
	return (NULL);
}
