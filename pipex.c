/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 05:07:31 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/03 03:57:04 by ttiprez          ###   ########.fr       */
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

bool	first_child_actions(char **argv, int pipefd[2])
{
	char	*cmd1;
	char	**cmd1argv;
	int		input_fd;

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		return (perror(argv[1]), false);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	dup2(input_fd, STDIN_FILENO);
	close(input_fd);
	cmd1argv = ft_split(argv[2], ' ');
	if (!cmd1argv)
		return (perror(argv[1]), false);
	cmd1 = malloc(ft_strlen(cmd1argv[0]) + 6);
	if (!cmd1)
		return (perror(cmd1argv[0]), free_split(cmd1argv), false);
	ft_strcpy(cmd1, "/bin/");
	ft_strcat(cmd1, cmd1argv[0]);
	execve(cmd1, cmd1argv, NULL);
	perror("execve");
	return (free(cmd1), free_split(cmd1argv), false);
}

int main(int argc, char const *argv[])
{
	int		output_fd;
	int		pipefd[2];
	pid_t	child;

	if (argc != 5)
		return (print_error("Error: Wrong number of arguments\n"));
	if (access(argv[1], R_OK) == -1)
		return (perror(argv[1]), EXIT_FAILURE);
	child = fork();
	if (child == -1)
		return (perror("fork"), EXIT_FAILURE);
	if (child == 0)
		if (!first_child_actions((char **)argv, pipefd))
			return (EXIT_FAILURE);
	wait(NULL);
	ft_printf("ici\n");
	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		return (perror(argv[4]), EXIT_FAILURE);
	close(output_fd);
	return (EXIT_SUCCESS);
}
