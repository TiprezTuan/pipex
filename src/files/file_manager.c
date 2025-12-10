/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:51:44 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/10 20:10:57 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static bool	read_stdin(int fd, char *eof)
{
	char	buf[100000];
	int		nb_read;
	char	*other_eof;

	other_eof = ft_strjoin(eof, "\n");
	if (!other_eof)
	{
		close(fd);
		return (false);
	}
	while (1)
	{
		ft_putstr_fd("> ", STDIN_FILENO);
		nb_read = read(0, buf, sizeof(buf) - 1);
		if (nb_read <= 0)
			break ;
		buf[nb_read] = 0;
		if (ft_strcmp(buf, eof) == 0 || ft_strcmp(buf, other_eof) == 0)
			break ;
		write(fd, buf, nb_read);
	}
	free(other_eof);
	return (true);
}

int	open_input_file(char *filename, char **av)
{
	int	input_fd;

	if (!is_heredoc(av))
		input_fd = open(filename, O_RDONLY);
	else
	{
		input_fd = open("/tmp/.pipex_heredoc", O_WRONLY | O_CREAT | O_TRUNC, \
			0644);
		if (input_fd < 0)
			return (perror("/tmp/.pipex_heredoc"), -1);
		if (!read_stdin(input_fd, av[2]))
			return (-2);
		close(input_fd);
		input_fd = open("/tmp/.pipex_heredoc", O_RDONLY);
		if (input_fd < 0)
			return (perror("/tmp/.pipex_heredoc"), -1);
	}
	return (input_fd);
}

int	open_output_file(char *filename, bool is_hd)
{
	int	output_fd;

	if (is_hd)
		output_fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		output_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (output_fd);
}
