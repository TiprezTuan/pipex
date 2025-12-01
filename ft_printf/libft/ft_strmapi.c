/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:21:01 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/05 17:33:42 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_copied;
	unsigned int	i;

	if (!s)
		return (NULL);
	str_copied = ft_strdup(s);
	if (!str_copied)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_copied[i] = f(i, s[i]);
		i++;
	}
	return (str_copied);
}
