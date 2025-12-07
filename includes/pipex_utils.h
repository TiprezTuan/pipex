/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:25:55 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 18:32:00 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

void	free_split(char **split);
void	free_result(char **result);
void	free_split_and_exit(char **split_to_free);
void	free_2_splits(char **a, char **b);
void	free_2_splits_and_exit(char **a, char **b);

int		print_error_and_exit(char *src_msg, char *msg);
void	perror_exit(char *perror_msg);

#endif