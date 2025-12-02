/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 05:07:31 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/02 19:13:45 by ttiprez          ###   ########.fr       */
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
	dup2(input_fd, 0); // copie input_fd dans stdin (0)

	char **cmd1argv = ft_split((char *)argv[2], ' ');
	if (!cmd1argv)
	{
		perror("malloc");
		close(input_fd);
		return (EXIT_FAILURE);
	}
	char cmd1[20];
	ft_strcpy(cmd1, "/bin/");
	ft_strcat(cmd1, cmd1argv[0]);
	ft_printf("cmd1 : %s\n", cmd1);
	for (int i = 0; cmd1argv[i]; i++) // print cmd1argv
	{
		ft_printf("cmd1argv[%d] : %s\n", i, cmd1argv[i]);
	}
	ft_printf("--------------------------\n");
	execve(cmd1, cmd1argv, NULL);

	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		perror(argv[4]);
		close(input_fd);
		return (EXIT_FAILURE);
	}

	close(input_fd);
	close(output_fd);
	return (EXIT_SUCCESS);
}
