/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:13:00 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/09 17:55:41 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (nb <= 1)
	{
		return (0);
	}
	while (i <= nb)
	{
		if (nb % i == 0)
		{
			j++;
		}
		if (j > 2)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) != 1)
	{
		nb++;
	}
	return (nb);
}

/*int	main(void)
{
	int		result;
	char	print;

	result = ft_find_next_prime(7);
	print = result + '0';
	write(1, &print, 1);
}*/
