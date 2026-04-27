/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:22:08 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/17 20:31:31 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_atoi(char *nbr, int *sign)
{
	int	i;
	int	length;

	*sign = 1;
	length = 0;
	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	base_to_int(char *nbr, char *base)
{
	int	i;
	int	r;
	int	j;
	int	length;
	int	sign;

	r = 0;
	length = 0;
	i = check_atoi(nbr, &sign);
	while (base[length])
		length++;
	while (nbr[i])
	{
		j = 0;
		while (base[j] && base[j] != nbr[i])
			j++;
		if (base[j] == '\0')
			break ;
		r = r * length + j;
		i++;
	}
	return (r * sign);
}

int	calc_len(int n, int base_len)
{
	int	len;
	int	tmp;

	len = 0;
	if (n <= 0)
		len++;
	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	while (tmp > 0)
	{
		tmp /= base_len;
		len++;
	}
	return (len);
}

void	fill_str(char *res, int len, int n, char *base)
{
	int	base_len;
	int	tmp;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	res[len] = '\0';
	while (len > 0)
	{
		len--;
		res[len] = base[tmp % base_len];
		tmp /= base_len;
	}
	if (n < 0)
		res[0] = '-';
}

char	*int_to_base(char *base, int n)
{
	int		len;
	char	*res;
	int		base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = calc_len(n, base_len);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	fill_str(res, len, n, base);
	return (res);
}
