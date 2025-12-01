/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:15:31 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/13 13:24:26 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*ascii_str;
	long	n;
	int		len;

	n = nb;
	len = ft_intlen(n);
	ascii_str = malloc(len + 1);
	if (!ascii_str)
		return (NULL);
	ascii_str[len--] = '\0';
	if (n == 0)
		ascii_str[0] = '0';
	if (n < 0)
	{
		ascii_str[0] = '-';
		n = -n;
	}
	while (n)
	{
		ascii_str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (ascii_str);
}
