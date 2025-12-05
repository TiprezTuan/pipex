/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:33:29 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/04 21:26:21 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

#include <stdbool.h>

char	*find_cmd_path(char *cmd, char **splitted_path);
bool	command(char *cmd_path, char *cmd, char **envp);

#endif