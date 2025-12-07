/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:25:26 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/07 16:35:41 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PARSING_H
# define PIPEX_PARSING_H

# include <stdbool.h>

char	*find_path(char **envp);

char	**ft_quotes_respected_split(char *str, char c);
int		ft_count_words(char *str, char c);
char	*ft_strndup(const char *src, unsigned int size);
bool	isquote(char quote, char c, bool check_both);
int		get_next_quote_i(char *str, char quote);

int		handle_heredoc(int ac, char **av);

#endif