/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:24:57 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 17:07:28 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PROCESS_H
# define PIPEX_PROCESS_H

#include <fcntl.h>

void	wait_all(pid_t last_pid);
void	first_child_action(int *pipefd, char **argv, char **envp);
pid_t	mid_child_action(int *pipe_in, int *pipe_out, char *cmd, char **envp);
pid_t	last_child_action(int *pipe_in, int ac, char **argv, char **envp);

char	*find_cmd_path(char **cmdargv, char **splitted_path);
void	command(char *cmd_path, char *cmd, char **envp);

void	init_pipes(int ***pipes, int nb_pipes);
void	close_pipes(int ***pipes, int nb_pipes, int pipe_to_keep);
void	close_pipe(int **pipe);

#endif