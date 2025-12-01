/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:50:24 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/30 01:29:14 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skip_whitespace(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] == ' ' || (src[i] >= 9 && src[i] <= 13))
		i++;
	return ((char *)&src[i]);
}

long	ft_atol(const char *src)
{
	long	res;
	int		i;
	int		signe;
	char	*str;

	str = ft_skip_whitespace(src);
	res = 0;
	signe = 1;
	i = 0;
	if (str[0] == '-')
	{
		signe = -1;
		i = 1;
	}
	else if (str[0] == '+')
		i = 1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * signe);
}
