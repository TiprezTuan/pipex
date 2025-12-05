/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_respected_split.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:57:02 by ttiprez           #+#    #+#             */
/*   Updated: 2025/12/05 04:58:39 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUOTE_RESPECTED_SPLIT_H
# define FT_QUOTE_RESPECTED_SPLIT_H

#include <stdbool.h>

char	**ft_quotes_respected_split(char *str, char c);
int		ft_count_words(char *str, char c);
char	*ft_strndup(const char *src, unsigned int size);
void	free_result(char **result);
bool	isquote(char quote, char c, bool check_both);
int		get_next_quote_i(char *str, char quote);

#endif