/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:52:02 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/10 20:02:28 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>

t_lstcmd	*new_lstcmd(char **envp)
{
	t_lstcmd	*new;

	new = malloc(sizeof(t_lstcmd));
	if (!new)
		return (NULL);
	new->cmd_split = NULL;
	new->cmd_with_path = NULL;
	new->envp = envp;
	new->next = NULL;
	return (new);
}

t_lstcmd	*add_lstcmd(t_lstcmd **start, t_lstcmd *to_add)
{
	t_lstcmd	*last;

	if (!*start)
	{
		*start = to_add;
		return (to_add);
	}
	last = *start;
	while (last->next)
		last = last->next;
	last->next = to_add;
	return (to_add);
}

void	free_lstcmd(t_lstcmd *lst)
{
	t_lstcmd	*next;

	if (!lst)
		return ;
	while (lst)
	{
		next = lst->next;
		if (lst->cmd_split)
			free_split(lst->cmd_split);
		if (lst->cmd_with_path)
			free(lst->cmd_with_path);
		free(lst);
		lst = next;
	}
}

/************************************************/
/*	Ajoute toutes les commandes dans la lstcmd	*/
/************************************************/
t_lstcmd	*init_lstcmd(bool is_hd, int ac, char **av, char **envp)
{
	t_lstcmd	*lst;
	t_lstcmd	*c;
	int			cmd_i;

	lst = NULL;
	cmd_i = -1;
	while (++cmd_i < ac - (3 + is_hd))
	{
		c = new_lstcmd(envp);
		if (!c)
			return (free_lstcmd(lst), NULL);
		c->cmd_split = ft_split_quotes(av[2 + cmd_i + is_hd]);
		if (!c->cmd_split)
			return (free_lstcmd(lst), free_lstcmd(c), NULL);
		if (c->cmd_split[0])
			c->cmd_with_path = get_cmd_with_path(c->cmd_split[0], \
				get_path(envp));
		add_lstcmd(&lst, c);
	}
	return (lst);
}
