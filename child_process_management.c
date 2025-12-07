/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:26:34 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 14:55:04 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void	wait_all(pid_t last_pid)
{
	waitpid(last_pid, 0, 0);
	while (wait(NULL) > 0)
		;
}

void	first_child_action(int *pipefd, char *f, char *cmdargv, char **envp)
{
	pid_t	child;
	char	**splitted_cmd;
	char	*cmd_path;
	char	*path;
	int		input_fd;

	child = fork();
	if (child == -1)
		perror_exit("fork");
	if (child == 0)
	{
		path = find_path(envp);
		input_fd = open(f, O_RDONLY);
		if (input_fd == -1)
			perror_exit(f);
		dup2(input_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close_pipe(&pipefd);
		close(input_fd);
		cmd_path = find_cmd_path(ft_split(cmdargv, ' '), ft_split(path, ':'));
		command(cmd_path, cmdargv, envp);
	}
	else
		close(pipefd[1]);
}

pid_t	mid_child_action(int *pipe_in, int *pipe_out, char *cmd, char **envp)
{
	pid_t	child;
	char	**splitted_cmd;
	char	*cmd_path;
	char	*path;

	child = fork();
	if (child == -1)
		perror_exit("fork");
	if (child == 0)
	{
		path = find_path(envp);
		dup2(pipe_in[0], STDIN_FILENO);
		dup2(pipe_out[1], STDOUT_FILENO);
		close_pipe(&pipe_in);
		close_pipe(&pipe_out);
		cmd_path = find_cmd_path(ft_split(cmd, ' '), ft_split(path, ':'));
		command(cmd_path, cmd, envp);
	}
	else
		return (close_pipe(&pipe_in), close(pipe_out[1]), child);
	return (child);
}

pid_t	last_child_action(int *pipe_in, int ac, char **argv, char **envp)
{
	pid_t	child;
	char	**splitted_cmd;
	char	*cmd_path;
	char	*path;
	int		output_fd;

	child = fork();
	if (child == -1)
		perror_exit("fork");
	if (child == 0)
	{
		path = find_path(envp);
		output_fd = open(argv[ac + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (output_fd == -1)
			perror_exit(argv[ac + 1]);
		dup2(pipe_in[0], STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		close_pipe(&pipe_in);
		close(output_fd);
		cmd_path = find_cmd_path(ft_split(argv[ac], ' '), ft_split(path, ':'));
		command(cmd_path, argv[ac], envp);
	}
	else
		return (close_pipe(&pipe_in), child);
	return (child);
}
