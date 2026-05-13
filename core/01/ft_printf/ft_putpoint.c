/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:29:15 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/13 18:22:44 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint_rec(unsigned long p)
{
	int	count;

	count = 0;
	if (p >= 16)
		count += ft_putpoint_rec(p / 16);
	if (p % 16 < 10)
		count += ft_putchar('0' + (p % 16));
	else
		count += ft_putchar('a' + (p % 16 - 10));
	return (count);
}

int	ft_putpoint(void *pointer)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putpoint_rec((unsigned long)pointer);
	return (count);
}
