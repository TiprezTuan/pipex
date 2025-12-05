/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:36:35 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 13:39:33 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	free_result(char **result)
{
	int	i;

	i = -1;
	while (result[++i])
		free(result[i]);
	free(result);
}

void	free_split_and_exit(char **split_to_free)
{
	if (split_to_free)
		free_split(split_to_free);
	exit(EXIT_FAILURE);
}

void	free_2_splits(char **a, char **b)
{
	if (a)
		free_split(a);
	if (b)
		free_split(b);
}

void	free_2_splits_and_exit(char **a, char **b)
{
	if (a)
		free_split(a);
	if (b)
		free_split(b);
	exit(EXIT_FAILURE);
}
