/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:50:12 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 05:45:34 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse_main_arg.h"
#include "pipex.h"
#include "error_behaviors.h"
#include "libft.h"
#include "ft_quotes_respected_split.h"

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{
	char	*path;
	int		pipefd[2];

	path = find_path(envp);
	if (argc != 5)
		print_error_and_exit("Wrong numbers of arguments(expected 5)\n");
	if (access(argv[0], R_OK) == -1)
		return (perror(argv[0]), EXIT_FAILURE);
	if (pipe(pipefd) == -1)
		return (perror("pipe"), EXIT_FAILURE);
	first_child_action(pipefd, path, argv, envp);
	write_pipe_in_fd(argv[4], pipefd);

	// Actions du parent
	close(pipefd[0]);
	close(pipefd[1]);

	return (EXIT_SUCCESS);
}

//int	main(int argc, char *argv[], char *envp[])
//{
//	int		pipefd[2];
//	pid_t	child;
//	pid_t	child2;

//	if (argc != 5)
//		return (print_error("Error: Wrong number of arguments (5 needed)\n"));
//	if (access(argv[1], R_OK) == -1)
//		return (perror(argv[1]), EXIT_FAILURE);
//	if (pipe(pipefd) == -1)
//		return (perror("pipe"), EXIT_FAILURE);
//	child = fork();
//	if (child == -1)
//		return (perror("fork"), EXIT_FAILURE);
//	if (child == 0)
//		if (!write_cmd_in_pipe(argv[1], ft_split(argv[2], ' '), find_path(envp), pipefd))
//			return (EXIT_FAILURE);
//	child2 = fork();
//	if (child2 == -1)
//		return (perror("fork"), EXIT_FAILURE);
//	if (child2 == 0)
//		if (!child2_action(argv, pipefd))
//			return (EXIT_FAILURE);
//	close(pipefd[0]);
//	close(pipefd[1]);
//	waitpid(child, NULL, 0);
//	waitpid(child2, NULL, 0);
//	return (EXIT_SUCCESS);
//}
