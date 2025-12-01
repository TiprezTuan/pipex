/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:28:34 by ttiprez           #+#    #+#             */
/*   Updated: 2025/11/17 18:05:39 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "utils.h"

int	end_excepetion(va_list *args)
{
	va_end(*args);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = -1;
	count = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i])
				count += check_format(format[i], args);
		}
		else if (format[i] == '%' && !format[i + 1])
			return (end_excepetion(&args));
		else
			count += ft_putchar_count(format[i]);
	}
	va_end(args);
	return (count);
}

int	check_format(char c, va_list args)
{
	unsigned int	arg;

	if (c == '%')
		return (ft_putchar_count('%'));
	else if (c == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_count(va_arg(args, int)));
	else if (c == 'c')
		return (ft_putchar_count(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr_count(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
	{
		arg = va_arg(args, unsigned int);
		if (c == 'x')
			return (ft_putunbr_base_count(arg, "0123456789abcdef"));
		return (ft_putunbr_base_count(arg, "0123456789ABCDEF"));
	}
	else if (c == 'p')
		return (ft_putptr_count(va_arg(args, void *)));
	else
		return (ft_putchar_count('%') + ft_putchar_count(c));
}

int	ft_putunbr_base_count(unsigned long nb, char *base)
{
	size_t	base_len;
	int		count;

	count = 0;
	base_len = ft_strlen(base);
	if (nb >= base_len)
		count += ft_putunbr_base_count(nb / base_len, base);
	ft_putchar_fd(base[nb % base_len], 1);
	return (count + 1);
}
