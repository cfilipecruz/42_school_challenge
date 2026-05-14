/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:03:58 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/14 17:58:05 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int u)
{
	unsigned int	i;

	i = 0;
	if (u > 9)
		i += ft_putnbr_u(u / 10);
	ft_putchar((u % 10) + '0');
	i++;
	return (i);
}
