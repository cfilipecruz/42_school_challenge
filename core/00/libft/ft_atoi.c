/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:07:05 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:43:06 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	skip_whitespaces(char *atr)
{
	int	counter;

	counter = 0;
	while (atr[counter] == ' ' || atr[counter] == '\t' || atr[counter] == '\n'
		|| atr[counter] == '\v' || atr[counter] == '\f' || atr[counter] == '\r')
	{
		counter++;
	}
	return (counter);
}

static int	count(char *atr, int *counter)
{
	int	sign;

	sign = 1;
	while (atr[*counter] == '+' || atr[*counter] == '-')
	{
		if (atr[*counter] == '-')
		{
			sign *= -1;
		}
		(*counter)++;
	}
	return (sign);
}

int	ft_atoi(char *atr)
{
	int	counter;
	int	sign;
	int	digit;

	counter = skip_whitespaces(atr);
	sign = count(atr, &counter);
	digit = 0;
	while (atr[counter] >= '0' && atr[counter] <= '9')
	{
		digit = digit * 10 + (atr[counter] - '0');
		counter++;
	}
	return (sign * digit);
}
