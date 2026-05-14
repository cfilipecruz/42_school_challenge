/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:58:57 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/14 18:54:39 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handleformats(char format, va_list args)
{
	int	total;

	total = 0;
	if (format == '%')
		total = total + ft_putchar('%');
	else if (format == 'c')
		total = total + ft_putchar(va_arg(args, int));
	else if (format == 's')
		total = total + ft_putstr((char *)va_arg(args, char *));
	else if (format == 'p')
		total = total + ft_putpoint((char *)va_arg(args, void *));
	else if(format == 'd' || format == 'i')
		total = total + ft_putnbr(va_arg(args, int));
	else if(format == 'u')
		total = total + ft_putnbr_u(va_arg(args,unsigned int));
	else if(format == 'x')
		total = total + ft_puthex(va_arg(args,unsigned int), 'x');
	else if(format == 'X')
		total = total + ft_puthex(va_arg(args,unsigned int), 'X');
	return (total);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total;
	va_list	args;

	va_start(args, format);
	i = 0;
	total = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total = total + ft_handleformats(format[i], args);
		}
		else
			total = total + ft_putchar(format[i]);
		i++;
	}
	return (total);
}
