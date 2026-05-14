/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:23:08 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/14 18:05:51 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	main(void)
{

	/* =============== Testing ++%++ =============== */
/* 	char char_percent;
	
	char_percent = '%';
	printf("\n-----------\n");
	ft_printf("%c\n", char_percent);
	printf("%c\n", char_percent);
	printf("\n-----------\n");
	ft_printf("%%\n");
	printf("%%\n"); */
	
	/* =============== Testing ++c++ =============== */
	/* char	char_a;
	char	char_b;
	char	char_c;
	
	char_a = 'a';
	char_b = 'b';
	char_c = 'c';
	printf("\n-----------\n");
	ft_printf("Olá %c %c %c teste \n", char_a, char_b, char_c);
	printf("Olá %c %c %c teste\n", char_a, char_b, char_c); */

	/* =============== Testing ++s++ =============== */
/*  char	*str_s_1;
	char	*str_s_2;
	char	*str_s_3;

	str_s_1 = "abcd";
	str_s_2 = "-123";
	str_s_3 = "e";
	printf("\n-----------\n");
	ft_printf("Olá %s %s %s teste\n", str_s_1, str_s_2, str_s_3);
	printf("Olá %s %s %s teste\n", str_s_1, str_s_2, str_s_3); */

	/* =============== Testing ++p++ =============== */

	/* char	*str_p_1;
	char	*str_p_2;
	char	*str_p_3;

	str_p_1 = "abcd";
	str_p_2 = "-123";
	str_p_3 = "e";
	printf("\n-----------\n");
	ft_printf("Olá %p %p %p teste\n", str_p_1, str_p_2, str_p_3);
	printf("Olá %p %p %p teste\n", str_p_1, str_p_2, str_p_3); */

	/* =============== Testing ++d && i++ =============== */
	
	/* int i_1;
	int i_2;
	int d_1;
	int d_2;

	i_1 = 10;
	i_2 = 0;
	d_1 = -2147483648;
	d_2 = 2147483647;

	printf("\n-----------\n");
	ft_printf("Olá %i %i %d %d teste\n", i_1, i_2, d_1, d_2);
	printf("Olá %i %i %d %d teste\n", i_1, i_2, d_1, d_2);
	 */

	 /* =============== Testing ++u++ =============== */
	 
/* 	unsigned u_1;
	unsigned u_2;
	unsigned u_3;

	u_1 = 10;
	u_2 = 0;
	u_3 = 4294967295;


	printf("\n-----------\n");
	ft_printf("Olá %u %u %u teste\n", u_1, u_2, u_3);
	printf("Olá %u %u %u teste\n", u_1, u_2, u_3);
	 */


	/* =============== Testing ++u++ =============== */
	unsigned x_1;
	unsigned x_2;
	unsigned x_3;
	unsigned X_1;
	unsigned X_2;
	unsigned X_3;

	x_1 = 10;
	x_2 = 0;
	x_3 = 4294967295;
	X_1 = 10;
	X_2 = 0;
	X_3 = 4294967295;


	printf("\n-----------\n");
	ft_printf("Olá %x %x %x teste\n", x_1, x_2, x_3);
	printf("Olá x%x %x %x teste\n", x_1, x_2, x_3);


	printf("\n-----------\n");
	ft_printf("Olá %X %X %X teste\n", X_1, X_2, X_3);
	printf("Olá X%X %X %X teste\n", X_1, X_2, X_3);
}
