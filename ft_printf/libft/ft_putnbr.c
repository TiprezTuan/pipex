/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:33:22 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/05 17:21:14 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char		mod;
	int			div;
	long int	n;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	mod = n % 10 + '0';
	div = n / 10;
	if (div != 0)
		ft_putnbr(div);
	write(1, &mod, 1);
}
