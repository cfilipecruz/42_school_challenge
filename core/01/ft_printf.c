/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:58:57 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/12 17:40:28 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		c;
	int		len;
	
	va_list	args;

	len = ft_strlen(format);
	va_start(args, format);
	va_arg(args, int);
	va_end len;*/
	i = 0;
	c = 5;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			ft_putchar('e');
		}
		i++;
	}
	return (c);
}

int	main(void)
{
	char	char_less_e;

	char_less_e = 'e';
	ft_printf("%c", char_less_e);
}
