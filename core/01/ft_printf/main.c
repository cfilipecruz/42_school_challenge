/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:23:08 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/13 15:58:45 by cmarques         ###   ########.fr       */
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

	char	*str_p_1;
	char	*str_p_2;
	char	*str_p_3;

	str_p_1 = "abcd";
	str_p_2 = "-123";
	str_p_3 = "e";
	printf("\n-----------\n");
	ft_printf("Olá %p %p %p teste\n", str_p_1, str_p_2, str_p_3);
	printf("Olá %p %p %p teste\n", str_p_1, str_p_2, str_p_3);
}
