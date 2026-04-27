/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:41:43 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/04 16:50:19 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	skip_whitespaces(char *atr)
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

int	count(char *atr, int *counter)
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
