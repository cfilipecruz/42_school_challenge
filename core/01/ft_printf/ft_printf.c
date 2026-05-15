/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:58:57 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/15 12:07:17 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handleformats(char format, va_list args)
{
	int	total;

	total = 0;
	if (format == '%')
		total += ft_putchar('%');
	else if (format == 'c')
		total += ft_putchar(va_arg(args, int));
	else if (format == 's')
		total += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		total += ft_putpoint(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		total += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		total += ft_putnbr_u(va_arg(args, unsigned int));
	else if (format == 'x')
		total += ft_puthex(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		total += ft_puthex(va_arg(args, unsigned int), 'X');
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

// #include <stdio.h>

// int main(void)
// {
// 	/* =============== VARIABLES =============== */

// 	char			char_percent;
// 	char			char_a;
// 	char			char_b;
// 	char			char_c;

// 	char			*str_s_1;
// 	char			*str_s_2;
// 	char			*str_s_3;
// 	char			*str_null;
// 	char			*str_empty;

// 	char			*str_p_1;
// 	char			*str_p_2;
// 	char			*str_p_3;
// 	void			*ptr_null;
// 	char			*ptr_a;
// 	char			*ptr_b;
// 	char			*ptr_c;

// 	int				i_1;
// 	int				i_2;
// 	int				d_1;
// 	int				d_2;
// 	int				d_a;
// 	int				d_b;
// 	int				d_c;

// 	unsigned int	u_1;
// 	unsigned int	u_2;
// 	unsigned int	u_3;
// 	unsigned int	u_a;
// 	unsigned int	u_b;

// 	unsigned int	x_1;
// 	unsigned int	x_2;
// 	unsigned int	x_3;
// 	unsigned int	X_1;
// 	unsigned int	X_2;
// 	unsigned int	X_3;
// 	unsigned int	x_a;
// 	unsigned int	x_b;

// 	/* =============== INIT VALUES =============== */

// 	char_percent = '%';

// 	char_a = 'a';
// 	char_b = 'b';
// 	char_c = 'c';

// 	str_s_1 = "abcd";
// 	str_s_2 = "-123";
// 	str_s_3 = "e";

// 	str_null = NULL;
// 	str_empty = "";

// 	str_p_1 = "abcd";
// 	str_p_2 = "-123";
// 	str_p_3 = "e";

// 	ptr_null = NULL;
// 	ptr_a = "abc";
// 	ptr_b = "def";
// 	ptr_c = "ghi";

// 	i_1 = 10;
// 	i_2 = 0;

// 	d_1 = -2147483648;
// 	d_2 = 2147483647;
// 	d_a = 0;
// 	d_b = -2147483648;
// 	d_c = 2147483647;

// 	u_1 = 10;
// 	u_2 = 0;
// 	u_3 = 4294967295;

// 	u_a = 0;
// 	u_b = 4294967295;

// 	x_1 = 10;
// 	x_2 = 0;
// 	x_3 = 4294967295;

// 	X_1 = 10;
// 	X_2 = 0;
// 	X_3 = 4294967295;

// 	x_a = 0;
// 	x_b = 4294967295;

// 	/* =============== TESTS =============== */

// 	printf("\n================ TEST %%%% ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("%c\n", char_percent));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("%c\n", char_percent));

// 	printf("REAL RETURN: %d\n",
// 		printf("%%\n"));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("%%\n"));

// 	printf("\n================ TEST CHAR ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("Olá %c %c %c teste\n", char_a, char_b, char_c));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("Olá %c %c %c teste\n", char_a, char_b, char_c));

// 	printf("\n================ TEST STRING ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("Olá %s %s %s teste\n", str_s_1, str_s_2, str_s_3));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("Olá %s %s %s teste\n", str_s_1, str_s_2, str_s_3));

// 	printf("\n================ TEST NULL STRING ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("REAL: %s\n", str_null));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("MINE: %s\n", str_null));

// 	printf("\n================ TEST EMPTY STRING ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("REAL: %s\n", str_empty));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("MINE: %s\n", str_empty));

// 	printf("\n================ TEST POINTERS ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("Olá %p %p %p\n", str_p_1, str_p_2, str_p_3));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("Olá %p %p %p\n", str_p_1, str_p_2, str_p_3));

// 	printf("\n================ TEST NULL POINTER ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("REAL: %p\n", ptr_null));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("MINE: %p\n", ptr_null));

// 	printf("\n================ TEST INT ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("Olá %i %i %d %d\n", i_1, i_2, d_1, d_2));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("Olá %i %i %d %d\n", i_1, i_2, d_1, d_2));

// 	printf("\n================ TEST INT EDGE ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("%d %d %d\n", d_a, d_b, d_c));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("%d %d %d\n", d_a, d_b, d_c));

// 	printf("\n================ TEST UNSIGNED ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("%u %u %u\n", u_1, u_2, u_3));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("%u %u %u\n", u_1, u_2, u_3));

// 	printf("\n================ TEST UNSIGNED EDGE ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("%u %u\n", u_a, u_b));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("%u %u\n", u_a, u_b));

// 	printf("\n================ TEST HEX ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("%x %X\n", x_a, x_b));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("%x %X\n", x_a, x_b));

// 	printf("\n================ TEST PERCENT ================\n");

// 	printf("REAL RETURN: %d\n",
// 		printf("%% %% %%\n"));
// 	printf("MINE RETURN: %d\n",
// 		ft_printf("%% %% %%\n"));

// 	return (0);
// }