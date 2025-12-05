/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 05:07:31 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 05:02:45 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "error_behaviors.h"
#include "command.h"
#include "ft_quotes_respected_split.h"

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

bool	write_pipe_in_fd(char *filename, int pipefd[2])
{
	char	buf[1024];
	int		nb_read;
	int		output_fd;

	close(pipefd[1]);
	output_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		return (perror(filename), false);
	nb_read = read(pipefd[0], buf, sizeof(buf));
	while (nb_read > 0)
	{
		write(output_fd, buf, nb_read);
		nb_read = read(pipefd[0], buf, sizeof(buf));
	}
	close(pipefd[0]);
	close(output_fd);
	return (true);
}

bool	child2_action(char **argv, int pipefd[2])
{
	if (!write_pipe_in_fd(argv[4], pipefd))
		return (false);
	return (true);
}

void	first_child_action(int *pipefd, char *path, char **argv, char **envp)
{
	pid_t	child;
	int		input_fd;
	char	**splitted_cmd;

	(void)path;
	(void)envp;
	child = fork();
	if (child == -1)
		perror_exit("fork");
	if (child == 0)
	{
		input_fd = open(argv[1], O_RDONLY);
		if (input_fd == -1)
			perror_exit(argv[1]);
		dup2(input_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(input_fd);
		splitted_cmd = ft_quotes_respected_split(argv[2], ' ');
		if (!command(find_cmd_path(splitted_cmd[0], ft_split(path, ':')), argv[2], envp))
			free_split_and_exit(splitted_cmd);
	}
}
