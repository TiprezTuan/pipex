/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:33:12 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/10 20:11:01 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

static bool	check_nb_args(int ac, char **av)
{
	if (ac < 5)
	{
		ft_putendl_fd("Error: Wrong number of arguments (Minimum 5)", 2);
		return (false);
	}
	if (is_heredoc(av))
	{
		if (ac < 6)
		{
			ft_putendl_fd("Error: Wrong number of arguments (Minimum 6)", 2);
			return (false);
		}
	}
	return (true);
}

static void	is_valid_input_fd(char	*filename)
{
	if (access(filename, F_OK) == -1)
		return (perror(filename));
	if (access(filename, R_OK) == -1)
		return (perror(filename));
}

/************************************************************************/
/*				Verifie l'integritee des arguments du main				*/
/*		(nb_args ok, input_fd existant, creation output_fd possible)	*/
/************************************************************************/
void	argv_checker(int ac, char **av)
{
	if (!check_nb_args(ac, av))
		exit(EXIT_FAILURE);
	if (!is_heredoc(av))
		is_valid_input_fd(av[1]);
}

/****************************************************/
/*	 Renvoie vrai si le programme est en here_doc	*/
/****************************************************/
bool	is_heredoc(char **av)
{
	return (ft_strcmp(av[1], "here_doc") == 0);
}
