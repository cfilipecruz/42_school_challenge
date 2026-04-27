/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:53:02 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/09 17:12:22 by cmarques         ###   ########.fr       */
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

/*int	main(void)
{
	if (ft_is_prime(9) == 1)
	{
		write(1, "Prime Number", 13);
	}
	else
	{
		write(1, "Not a Prime Number", 20);
	}
}*/
