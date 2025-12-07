/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:16:17 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 17:02:57 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex_utils.h"
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

static void	read_stdin(int fd, char *eof)
{
	char	buf[100000];
	int		nb_read;
	char	*other_eof;

	other_eof = ft_strjoin(eof, "\n");
	if (!other_eof)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		nb_read = read(0, buf, sizeof(buf) - 1);
		if (nb_read <= 0)
			break;
		buf[nb_read] = 0;
		if (ft_strcmp(buf, eof) == 0 || ft_strcmp(buf, other_eof) == 0)
			break;
		write(fd, buf, nb_read);
	}
	close(fd);
}

int	handle_heredoc(int ac, char **av)
{
	int	fd;

	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			print_error_and_exit("Wrong numbers of arguments (minimum 6)\n");
		fd = open("/tmp/.pipex_heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			perror_exit("/tmp/.pipex_heredoc");
		read_stdin(fd, av[2]);
		fd = open("/tmp/.pipex_heredoc", O_RDONLY);
		if (fd < 0)
			perror("/tmp/.pipex_heredoc");
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			perror_exit(av[1]);
	}
	return (fd);
}
