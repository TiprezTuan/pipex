/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:27:50 by ttiprez           #+#    #+#             */
/*   Updated: 2025/09/09 15:40:05 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	char		mod;
	int			div;
	long int	n;

	if (fd < 0)
		return ;
	n = nb;
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	mod = n % 10 + '0';
	div = n / 10;
	if (div != 0)
		ft_putnbr_fd(div, fd);
	write(fd, &mod, 1);
}
