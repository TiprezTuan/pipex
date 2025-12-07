/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:21:36 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 17:09:35 by ttiprez          ###   ########.fr       */
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
	int		i;
	int		nb_cmd;
	int		**pipes;

	nb_cmd = ac - 3;
	if (ft_strcmp(av[1], "here_doc") == 0)
		nb_cmd = ac - 4;
	init_pipes(&pipes, ac - nb_cmd - 1);
	first_child_action(pipes[0], ac,
		av, envp);
	i = 0;
	while (i < nb_cmd - 1)
	{
		last_pid = mid_child_action(pipes[i], pipes[i + 1],
				av[ac - 2 - 1 - i], envp);
		i++;
	}
	last_pid = last_child_action(pipes[i], ac - 2, av, envp);
	wait_all(last_pid);
	if (ft_strcmp(av[1], "here_doc"))
		unlink("/tmp/.pipex_heredoc");
	close_pipes_and_free(&pipes, ac - 4);
	return (EXIT_SUCCESS);
}
