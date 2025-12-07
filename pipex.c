/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:21:36 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 18:57:47 by ttiprez          ###   ########.fr       */
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

static void check_ac(int ac, char **av)
{
	if (ac < 5)
		print_error_and_exit("Error", ": wrong number of arguments");
	else if (ft_strcmp(av[1], "here_doc") == 0 && ac < 6)
		print_error_and_exit("Error", ": wrong number of arguments");
}

int	main(int ac, char **av, char **envp)
{
	pid_t	last_pid;
	int		i;
	int		cmd_i;
	int		**pipes;
	int		nb_pipes;

	check_ac(ac, av);
	cmd_i = 2;
	if (ft_strcmp(av[1], "here_doc") == 0)
		cmd_i = 3;
	if (cmd_i == 2 && access(av[1], R_OK) == -1)
		print_error_and_exit(av[1], "no such file or directory");
	nb_pipes = ac - cmd_i - 2;
	init_pipes(&pipes, nb_pipes);
	first_child_action(pipes[0], ac, av, envp);
	cmd_i++;
	i = -1;
	while (++i < nb_pipes - 1)
		last_pid = mid_child_action(pipes[i], pipes[i + 1],
				av[cmd_i++], envp);
	last_pid = last_child_action(pipes[i], ac - 2, av, envp);
	if (ft_strcmp(av[1], "here_doc") == 0)
		unlink("/tmp/.pipex_heredoc");
	close_pipes_and_free(&pipes, nb_pipes);
	return (wait_all(last_pid));
}
