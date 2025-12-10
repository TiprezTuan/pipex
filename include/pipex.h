/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:55:45 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/10 19:58:18 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <stdbool.h>

/************************************************************/
/* Definition des constantes et codes de retour          */
/************************************************************/
# define CMD_NOT_FOUND 127
# define CMD_EXEC_ERROR 126

/************************************************************/
/* Definition de la structure des commandes               */
/************************************************************/
typedef struct s_lstcmd
{
	char				**cmd_split;
	char				*cmd_with_path;
	char				**envp;
	struct s_lstcmd		*next;
}	t_lstcmd;

/*****************************/
/*		 args_check.c		 */
/*****************************/
bool		is_heredoc(char **av);
void		argv_checker(int ac, char **av);

/*****************************/
/*		 path_parsing.c		 */
/*****************************/
char		*get_path(char **envp);
char		*get_cmd_with_path(char *cmd, char *path);

/*****************************/
/*		 split_quotes.c		 */
/*****************************/
char		**ft_split_quotes(char *s);

/*****************************/
/*		 split_utils.c		 */
/*****************************/
int			is_quote(char c);
char		*skip_spaces(char *s);
char		*skip_quote(char *s, char quote);
int			count_words(char *s);
int			word_len(char *s);

/*****************************/
/*		 pipe_exec.c		 */
/*****************************/
int			wait_for_children(pid_t last_pid);
int			execute_pipeline(t_lstcmd *lst, int fd_in, int fd_out);

/*****************************/
/*		 child_exec.c		 */
/*****************************/
int			child_action(t_lstcmd *lst, t_lstcmd *cmd, int from, int to);

/*****************************/
/*		 file_manager.c		 */
/*****************************/
int			open_input_file(char *filename, char **av);
int			open_output_file(char *filename, bool is_hd);

/*****************************/
/*		  cmd_list.c		 */
/*****************************/
t_lstcmd	*new_lstcmd(char **envp);
t_lstcmd	*add_lstcmd(t_lstcmd **start, t_lstcmd *to_add);
void		free_lstcmd(t_lstcmd *lst);
t_lstcmd	*init_lstcmd(bool is_hd, int ac, char **av, char **envp);

/*****************************/
/*		   cleanup.c		 */
/*****************************/
void		free_split(char **result);
void		cleanup(t_lstcmd *lst, int fd_in, int fd_out);

#endif