/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:21:36 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 16:53:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int ac, char **av, char **envp)
{
	pid_t	last_pid;
	char	*path;
	int		i_cmd;
	int		i;
	int		**pipes;

	init_pipes(&pipes, ac - 3 - 1);
	path = find_path(envp);
	if (ac < 5)
		print_error_and_exit("Wrong numbers of arguments(Minimum 5)\n");
	if (access(av[0], R_OK) == -1)
		return (perror(av[0]), EXIT_FAILURE);
	first_child_action(pipes[0], av, envp);
	i_cmd = 3;
	i = 0;
	while (i_cmd < ac - 2)
	{
		last_pid = mid_child_action(pipes[i], pipes[i + 1], av[i_cmd], envp);
		i++;
		i_cmd++;
	}
	last_pid = last_child_action(pipes[i], ac - 2, av, envp);
	close_pipes(&pipes, ac - 4, -1);
	wait_all(last_pid);
	return (EXIT_SUCCESS);
}
