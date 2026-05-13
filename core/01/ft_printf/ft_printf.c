/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:58:57 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/13 14:57:55 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (format[i] == '%')
				total = total + ft_putchar('%');
			else if (format[i] == 'c')
				total = total + ft_putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				total = total + ft_putstr((char *)va_arg(args, char *));
			}
		}
		else
			total = total + ft_putchar(format[i]);
		i++;
	}
	return (total);
}

int	main(void)
{

	/* =============== Testing ++%++ =============== */
	char char_percent;

	ft_printf("%%");
	printf("%%");
	
	/* =============== Testing ++c++ =============== */
	/* char	char_a;
	char	char_b;
	char	char_c;
	char_a = 'a';
	char_b = 'b';
	char_c = 'c';
	ft_printf("Olá %c %c %c teste \n", char_a, char_b, char_c);
	printf("Olá %c %c %c teste", char_a, char_b, char_c); */

	/* =============== Testing ++s++ =============== */
	char	*str_1;
	char	*str_2;
	char	*str_3;

	str_1 = "abcd";
	str_2 = "-123";
	str_3 = "e";
	
	ft_printf("Olá %s %s %s teste\n", str_1, str_2, str_3);
	printf("Olá %s %s %s teste", str_1, str_2, str_3);
}
