/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:28:36 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 19:06:18 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void	print_err_free_splits_exit(char *err_msg, char **s1, char **s2)
{
	ft_putstr_fd(err_msg, 2);
	ft_putendl_fd(": command not found", 2);
	free_2_splits_and_exit(s1, s2);
}

char	*loop_find_cmd_path(char **cmdargv, char **splitted_path)
{
	char	*cmd_path;
	char	*tmp;
	size_t	i;

	i = -1;
	while (splitted_path[++i])
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
	}
	print_err_free_splits_exit(cmdargv[0], cmdargv, splitted_path);
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **splitted_path)
{
	char	**cmdargv;

	if (ft_strcmp(cmd, "") == 0)
	{
		free_split(splitted_path);
		print_error_and_exit("", ": command not found");
	}
	else
		cmdargv = ft_split(cmd, ' ');
	if (!cmdargv)
		free_2_splits_and_exit(cmdargv, splitted_path);
	if (ft_strchr(cmdargv[0], '/'))
		if (access(cmdargv[0], X_OK) == 0)
			return (ft_strdup(cmdargv[0]));
	if (!splitted_path)
		print_err_free_splits_exit(cmdargv[0], cmdargv, splitted_path);
	return (loop_find_cmd_path(cmdargv, splitted_path));
}

void	command(char *cmd_path, char *cmdargv, char **envp)
{
	char	**splitted_cmd;

	if (!cmd_path)
		exit(EXIT_FAILURE);
	splitted_cmd = ft_quotes_respected_split(cmdargv, ' ');
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
