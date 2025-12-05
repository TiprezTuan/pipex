/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_behaviors.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:55:21 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 00:32:58 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BEHAVIORS_H
# define ERROR_BEHAVIORS_H

void	free_split(char **split);
int		print_error_and_exit(char *msg);
void	perror_exit(char *perror_msg);
void	free_split_and_exit(char **split_to_free);

#endif