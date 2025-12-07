/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:38:00 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 18:40:45 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_error_and_exit(char *src_msg, char *msg)
{
	if (src_msg)
		ft_putstr_fd(src_msg, 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	perror_exit(char *perror_msg)
{
	perror(perror_msg);
	exit (EXIT_FAILURE);
}
