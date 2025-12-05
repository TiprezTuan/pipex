/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:29:30 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 11:30:09 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	init_pipes(int ***pipes, int nb_pipes)
{
	int	i;
	int	j;
	
	*pipes = malloc(sizeof(int *) * nb_pipes);
	if (!*pipes)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < nb_pipes)
	{
		(*pipes)[i] = malloc(sizeof(int) * 2);
		if (!(*pipes)[i])
		{
			j = -1;
			while (++j < i)
				free((*pipes)[j]);
			free(*pipes);
			exit(EXIT_FAILURE);
		}
		pipe((*pipes)[i]);
	}
}

void	close_pipes(int ***pipes, int nb_pipes, int pipe_to_keep)
{
	int	i;

	i = -1;
	while (++i < nb_pipes)
		if (i != pipe_to_keep)
		{
			close((*pipes)[i][0]);
			close((*pipes)[i][1]);
		}
}