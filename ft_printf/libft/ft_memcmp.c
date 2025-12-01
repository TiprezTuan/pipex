/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:06:02 by ttiprez           #+#    #+#             */
/*   Updated: 2025/09/03 15:35:40 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = pointer1;
	p2 = pointer2;
	i = -1;
	while (++i < size)
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
	return (0);
}
