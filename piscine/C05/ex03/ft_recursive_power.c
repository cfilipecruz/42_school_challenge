/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:42:31 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/04 20:29:42 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	result = ft_recursive_power(nb, power - 1);
	result = result * nb;
	return (result);
}

/*int	main(void)
{
	int result;

	result = ft_recursive_power(5, 5);
	printf("Done = %i", result);
}*/