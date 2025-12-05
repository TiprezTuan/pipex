/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:28:36 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 17:15:06 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*find_cmd_path(char **cmdargv, char **splitted_path)
{
	char	*cmd_path;
	char	*tmp;
	size_t	i;

	if (!cmdargv || !splitted_path)
		free_2_splits_and_exit(cmdargv, splitted_path);
	i = 0;
	while (splitted_path[i])
	{
		tmp = ft_strjoin(splitted_path[i], "/");
		if (!tmp)
			free_2_splits_and_exit(cmdargv, splitted_path);
		cmd_path = ft_strjoin(tmp, cmdargv[0]);
		free(tmp);
		if (!cmd_path)
			free_2_splits_and_exit(cmdargv, splitted_path);
		if (access(cmd_path, X_OK) == 0)
			return (free_2_splits(cmdargv, splitted_path), cmd_path);
		free(cmd_path);
		i++;
	}
	free_2_splits_and_exit(cmdargv, splitted_path);
	return (NULL);
}

#include "ft_printf.h"

void	command(char *cmd_path, char *cmd, char **envp)
{
	char	**splitted_cmd;

	if (!cmd_path)
		exit(EXIT_FAILURE);
	splitted_cmd = ft_quotes_respected_split(cmd, ' ');
	if (!splitted_cmd)
	{
		free(cmd_path);
		exit(EXIT_FAILURE);
	}
	execve(cmd_path, splitted_cmd, envp);
	perror(splitted_cmd[0]);
	free(cmd_path);
	free_split_and_exit(splitted_cmd);
}
