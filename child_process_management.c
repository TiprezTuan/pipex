/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:26:34 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 17:07:44 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

static bool	is_heredoc(char **av)
{
	if (ft_strcmp(av[1], "here_doc") == 0)
		return (true);
	return (false);
}

void	wait_all(pid_t last_pid)
{
	waitpid(last_pid, 0, 0);
	while (wait(NULL) > 0)
		;
}

void	first_child_action(int *pipefd, int ac, char **av, char **envp)
{
	pid_t	child;
	char	*cmd_path;
	char	*path;
	int		input_fd;
	bool	skip_heredoc;

	child = fork();
	if (child == -1)
		perror_exit("fork");
	if (child == 0)
	{
		skip_heredoc = is_heredoc(av);
		path = find_path(envp);
		input_fd = handle_heredoc(ac, av);
		dup2(input_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close_pipe(&pipefd);
		close(input_fd);
		cmd_path = find_cmd_path(ft_split(av[2 + skip_heredoc], ' '),
				ft_split(path, ':'));
		command(cmd_path, av[2 + skip_heredoc], envp);
	}
	else
		close(pipefd[1]);
}

pid_t	mid_child_action(int *pipe_in, int *pipe_out, char *cmd, char **envp)
{
	pid_t	child;
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
	char	*cmd_path;
	char	*path;
	int		output_fd;

	child = fork();
	if (child == -1)
		perror_exit("fork");
	if (child == 0)
	{
		path = find_path(envp);
		if (is_heredoc(argv))
			output_fd = open(argv[ac + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
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
	return (close_pipe(&pipe_in), child);
}
