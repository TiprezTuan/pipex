/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_behaviors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:55:00 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 00:32:55 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	print_error_and_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	perror_exit(char *perror_msg)
{
	perror(perror_msg);
	exit (EXIT_FAILURE);
}

void	free_split_and_exit(char **split_to_free)
{
	free_split(split_to_free);
	exit(EXIT_FAILURE);
}