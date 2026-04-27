/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:07:43 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/09 16:52:07 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb / i)
	{
		if (i * i == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	int		result;
	char	c;

	result = ft_sqrt(9);
	if (result >= 0 && result <= 9)
	{
		c = result + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}*/
