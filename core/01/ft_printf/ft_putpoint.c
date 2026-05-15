/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:29:15 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/15 12:03:36 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putpointhex(unsigned long p)
{
	int	count;

	count = 0;
	if (p >= 16)
		count += ft_putpointhex(p / 16);
	if (p % 16 < 10)
		count += ft_putchar('0' + (p % 16));
	else
		count += ft_putchar('a' + (p % 16 - 10));
	return (count);
}

int	ft_putpoint(void *pointer)
{
	int	count;

	if (!pointer)
		return (write(1, "(nil)", 5));
	count = 0;
	count += ft_putstr("0x");
	count += ft_putpointhex((unsigned long)pointer);
	return (count);
}
