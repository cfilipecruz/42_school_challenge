/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:05:42 by cmarques          #+#    #+#             */
/*   Updated: 2026/04/25 15:55:06 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			i;
	const char	*string1;
	const char	*string2;

	i = 0;
	string1 = (const char *)s1;
	string2 = (const char *)s2;
	while (n != 0)
	{
		if (string1[i] != string2[i])
			return ((unsigned char)string1[i] - (unsigned char)string2[i]);
		i++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>

int	print_results(int result)
{
	if (result > 0)
	{
		printf("S1 is bigger\n");
	}
	else if (result < 0)
	{
		printf("S2 is bigger\n");
	}
	else
	{
		printf("Equal \n");
	}
	return (0);
}

int	main(void)
{
	int	result;

	result = ft_memcmp("abc", "abd", 3);
	print_results(result);
	result = ft_memcmp("abc", "abd", 0);
	print_results(result);
	result = ft_memcmp("abcd", "ab", 6);
	print_results(result);
	result = ft_memcmp("ab", "abd", 2);
	print_results(result);
	result = ft_memcmp("ab", "abd", 3);
	print_results(result);
	return (0);
}
*/