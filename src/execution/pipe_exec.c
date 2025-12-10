/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:49:01 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/10 21:04:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	wait_for_children(pid_t last_pid)
{
	int		status;
	int		exit_code;
	pid_t	pid;

	exit_code = 0;
	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (pid == last_pid)
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = 128 + WTERMSIG(status);
		}
	}
	return (exit_code);
}

int	execute_pipeline(t_lstcmd *lst, int fd_in, int fd_out)
{
	t_lstcmd	*current;
	int			pipe_fd[2];
	int			input_fd;
	int			output_fd;
	int			last_pid;

	current = lst;
	input_fd = fd_in;
	last_pid = 0;
	while (current)
	{
		output_fd = fd_out;
		if (current->next)
		{
			if (pipe(pipe_fd) == -1)
				return (perror("pipe"), -1);
			output_fd = pipe_fd[1];
		}
		last_pid = child_action(lst, current, input_fd, output_fd);
		if (current->next)
			input_fd = pipe_fd[0];
		current = current->next;
	}
	return (wait_for_children(last_pid));
}
