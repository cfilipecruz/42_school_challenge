/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:00:42 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/04 19:06:15 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;
	int	presult;
	int	initial;

	initial = nb;
	presult = nb + '0';
	nb--;
	if (initial < 0)
	{
		return (0);
	}
	if (nb >= 0)
	{
		result = ft_recursive_factorial(nb);
		result *= initial;
		return (result);
	}
	else
	{
		return (1);
	}
}
