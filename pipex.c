/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:21:36 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 15:06:36 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int ac, char **av, char **envp)
{
	pid_t	last_pid;
	int		i_cmd;
	int		i;
	int		nb_cmd;
	int		**pipes;

	f = get_filename(av, ac, &nb_cmd);
	init_pipes(&pipes, ac - nb_cmd - 1);
	first_child_action(pipes[0], f, av[ac - nb_cmd], envp);
	i_cmd = 0;
	i = 0;
	while (i_cmd < nb_cmd - 1)
	{
		last_pid = mid_child_action(pipes[i], pipes[i + 1], av[i_cmd], envp);
		i++;
		i_cmd++;
	}
	last_pid = last_child_action(pipes[i], ac - 2, av, envp);
	close_pipes_and_free(&pipes, ac - 4);
	wait_all(last_pid);
	return (EXIT_SUCCESS);
}
