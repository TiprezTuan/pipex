/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:24:57 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 13:40:06 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PROCESS_H
# define PIPEX_PROCESS_H

#include <unistd.h>

void	first_child_action(int *pipefd, char **argv, char **envp);
pid_t	next_childs_action(int *pipefd, char *cmd, char **envp);
void	last_child_action(int argc, char **argv, char **envp);

char	*find_cmd_path(char **cmdargv, char **splitted_path);
void	command(char *cmd_path, char *cmd, char **envp);

void	init_pipes(int ***pipes, int nb_pipes);
void	close_pipes(int ***pipes, int nb_pipes, int pipe_to_keep);

#endif