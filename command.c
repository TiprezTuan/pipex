/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:01:56 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 01:15:15 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include "libft.h"
#include "error_behaviors.h"
#include "ft_quotes_respected_split.h"

char	*find_cmd_path(char *cmd, char **splitted_path)
{
	char	*cmd_path;
	char	*tmp;
	size_t	i;

	if (!splitted_path)
		exit (EXIT_FAILURE);
	i = 0;
	while (splitted_path[i])
	{
		tmp = ft_strjoin(splitted_path[i], "/");
		if (!tmp)
			return (free_split(splitted_path), NULL);
		cmd_path = ft_strjoin(tmp, cmd);
		if (!cmd_path)
			return (free_split(splitted_path), free(tmp), NULL);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
			return (free_split(splitted_path), cmd_path);
		free(cmd_path);
		i++;
	}
	return (free_split(splitted_path), NULL);
}

bool	command(char *cmd_path, char *cmd, char **envp)
{
	char **splitted_cmd;

	if (!cmd_path)
		return (false);
	splitted_cmd = ft_quotes_respected_split(cmd, ' ');
	if (!splitted_cmd)
		return (false);
	execve(cmd_path, splitted_cmd, envp);
	free_split(splitted_cmd);
	perror(cmd_path);
	exit(EXIT_FAILURE);
}