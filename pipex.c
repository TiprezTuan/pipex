/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:21:36 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 13:28:17 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	pid_t	last_pid;
	char	*path;
	int		i_cmd;
	int		i_pipe;
	int		**pipefd_2d;

	init_pipes(&pipefd_2d, argc - 3 - 1);
	path = find_path(envp);
	if (argc < 5)
		print_error_and_exit("Wrong numbers of arguments(Minimum 5)\n");
	if (access(argv[0], R_OK) == -1)
		return (perror(argv[0]), EXIT_FAILURE);
	first_child_action(pipefd_2d[0], argv, envp);
	i_cmd = 3;
	i_pipe = 0;
	while (++i_cmd < argc)
		last_pid = next_childs_action(pipefd_2d[i_pipe++], argv[i_cmd], envp);
	waitpid(last_pid, 0, 0);
	last_child_action(argc, argv, envp);
	close_pipes(&pipefd_2d, i_pipe, -1);
	return (EXIT_SUCCESS);
}