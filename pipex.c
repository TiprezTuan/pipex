/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 05:07:31 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/03 18:45:05 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

char	*find_path(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
	return (NULL);
}

char	*find_cmd_path(char *cmd, char *path)
{
	char	**splitted_path;
	char	*cmd_path;
	char	*tmp;
	int		i;

	splitted_path = ft_split(path, ':');
	if (!splitted_path)
		exit (EXIT_FAILURE);
	i = -1;
	while (splitted_path[++i])
	{
		tmp = ft_strjoin(splitted_path[i], "/");
		if (!tmp)
			exit (EXIT_FAILURE);
		cmd_path = ft_strjoin(tmp, cmd);
		if (!cmd_path)
			exit (EXIT_FAILURE);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
		{
			free_split(splitted_path);
			return (cmd_path);
		}
		free(cmd_path);
	}
	return (free_split(splitted_path), NULL);
}

bool	command(char *cmd_path, char **cmdargv)
{
	execve(cmd_path, cmdargv, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

bool	write_cmd_in_pipe(char *file, char **cmdargv, char *path, int pipefd[2])
{
	int		input_fd;

	if (!cmdargv || !path)
		exit (EXIT_FAILURE);
	close(pipefd[0]);
	input_fd = open(file, O_RDONLY);
	if (input_fd == -1)
		return (perror(file), false);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(input_fd, STDIN_FILENO);
	close(pipefd[1]);
	close(input_fd);
	if (!command(find_cmd_path(cmdargv[0], path), cmdargv))
		return (false);
	return (true);
}

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

int	main(int argc, char *argv[], char *envp[])
{
	int		pipefd[2];
	pid_t	child;
	pid_t	child2;

	if (argc != 5)
		return (print_error("Error: Wrong number of arguments (5 needed)\n"));
	if (access(argv[1], R_OK) == -1)
		return (perror(argv[1]), EXIT_FAILURE);
	if (pipe(pipefd) == -1)
		return (perror("pipe"), EXIT_FAILURE);
	child = fork();
	if (child == -1)
		return (perror("fork"), EXIT_FAILURE);
	if (child == 0)
		if (!write_cmd_in_pipe(argv[1], ft_split(argv[2], ' '), find_path(envp), pipefd))
			return (EXIT_FAILURE);
	child2 = fork();
	if (child2 == -1)
		return (perror("fork"), EXIT_FAILURE);
	if (child2 == 0)
		if (!child2_action(argv, pipefd))
			return (EXIT_FAILURE);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(child, NULL, 0);
	waitpid(child2, NULL, 0);
	return (EXIT_SUCCESS);
}
