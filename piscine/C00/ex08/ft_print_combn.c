/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:18:01 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/11 14:29:00 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_comb(int *comb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &("0123456789"[comb[i]]), 1);
		i++;
	}
}

void	ft_reset_right(int *comb, int n, int i)
{
	while (i < n)
	{
		comb[i] = comb[i - 1] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[9];
	int	i;

	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
	}
	while (1)
	{
		ft_put_comb(comb, n);
		i = n - 1;
		while (i >= 0 && comb[i] == 10 - n + i)
			i--;
		if (i < 0)
			break ;
		comb[i]++;
		i++;
		ft_reset_right(comb, n, i);
		write(1, ", ", 2);
	}
}

/*int	main(void)
{
	ft_print_combn(3); // Output: 012, 013, ..., 789
}*/
