/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:26:34 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 13:18:14 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

void	first_child_action(int *pipefd, char **argv, char **envp)
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
		input_fd = open(argv[1], O_RDONLY);
		if (input_fd == -1)
			perror_exit(argv[1]);
		dup2(input_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(input_fd);
		cmd_path = find_cmd_path(ft_split(argv[2], ' '), ft_split(path, ':'));
		command(cmd_path, argv[2], envp);
	}
}

pid_t	next_childs_action(int *pipefd, char *cmd, char **envp)
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
		dup2(pipefd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		cmd_path = find_cmd_path(ft_split(cmd, ' '), ft_split(path, ':'));
		command(cmd_path, cmd, envp);
	}
	return (child);
}

void	last_child_action(int argc, char **argv, char **envp)
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
		output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
		if (output_fd == -1)
			perror_exit(argv[1]);
		dup2(STDOUT_FILENO, output_fd);
		close(output_fd);
		cmd_path = find_cmd_path(ft_split(argv[2], ' '), ft_split(path, ':'));
		command(cmd_path, argv[2], envp);
	}
}
