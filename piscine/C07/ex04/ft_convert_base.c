/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:47:00 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/17 20:24:31 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_to_int(char *nbr, char *base);
char	*int_to_base(char *base, int n);

int	check_duplicates(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2 || check_duplicates(base) == 0)
		return (0);
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;

	if (validate_base(base_from) == 0 || validate_base(base_to) == 0)
		return (NULL);
	i = base_to_int(nbr, base_from);
	return (int_to_base(base_to, i));
}
/*
#include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	char	*res;

	res = ft_convert_base("42", "0123456789", "01");
	printf("42 in binary: %s\n", res);
	free(res);
	res = ft_convert_base("101010", "01", "0123456789");
	printf("101010 in decimal: %s\n", res);
	free(res);
	res = ft_convert_base("1A", "0123456789ABCDEF", "0123456789");
	printf("1A in decimal: %s\n", res);
	free(res);
	res = ft_convert_base("255", "0123456789", "0123456789ABCDEF");
	printf("255 in hex: %s\n", res);
	free(res);
	res = ft_convert_base("-42", "0123456789", "01");
	printf("-42 in binary: %s\n", res);
	free(res);
	res = ft_convert_base("42", "0123456789+", "01");
	if (!res)
		printf("Invalid base detected\n");
	return (0);
}*/
