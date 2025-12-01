/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 05:07:31 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/01 16:01:51 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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

int main(int argc, char const *argv[])
{
	int		input_fd;
	int		output_fd;
	
	if (argc != 5)
		return (print_error("Error: Wrong number of arguments\n"));
	if (access(argv[1], R_OK) == -1)
		return (EXIT_FAILURE);

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
	{
		perror(argv[1]);
		return (EXIT_FAILURE);
	}

	pid_t pid = fork();
	
	if (pid == 0)
	{
		dup2(input_fd, 0);
		char *catargv[] = {"cat", NULL, NULL};
		execve("/bin/cat", catargv, NULL); // L'enfant s'arrete ici (Le programme est remplace par celui lance par execve)
		perror("execve");
		return (EXIT_FAILURE);
	}
	wait(NULL); // attend que l'enfant ai fini

	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		perror(argv[4]);
		close(input_fd);
		return (EXIT_FAILURE);
	}

	close (input_fd);
	close(output_fd);
	return (EXIT_SUCCESS);
}
