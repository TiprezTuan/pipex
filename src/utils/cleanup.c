/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:52:29 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/10 20:09:37 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>
#include <stdlib.h>

void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	cleanup(t_lstcmd *lst, int fd_in, int fd_out)
{
	if (lst)
		free_lstcmd(lst);
	close(fd_in);
	close(fd_out);
}
