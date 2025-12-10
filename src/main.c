/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:23:34 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/10 20:01:08 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>

int	main(int ac, char **av, char **envp)
{
	t_lstcmd	*lstcmd;
	int			fd_in;
	int			fd_out;
	int			exit_status;

	argv_checker(ac, av);
	fd_out = open_output_file(av[ac - 1], is_heredoc(av));
	fd_in = open_input_file(av[1], av);
	if (fd_in == -2)
		return (cleanup(NULL, fd_in, fd_out), EXIT_FAILURE);
	lstcmd = init_lstcmd(is_heredoc(av), ac, av, envp);
	if (!lstcmd)
		return (cleanup(NULL, fd_in, fd_out), EXIT_FAILURE);
	exit_status = execute_pipeline(lstcmd, fd_in, fd_out);
	return (cleanup(lstcmd, fd_in, fd_out), exit_status);
}
