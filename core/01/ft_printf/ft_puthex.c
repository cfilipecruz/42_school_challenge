/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:35:23 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/14 18:50:44 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int p, char format)
{
	int		count;
	char	base;

	count = 0;
	if (format == 'x')
		base = 'a';
	else
		base = 'A';
	if (p >= 16)
		count += ft_puthex(p / 16, format);
	if (p % 16 < 10)
		count += ft_putchar('0' + (p % 16));
	else
		count += ft_putchar(base + (p % 16 - 10));
	return (count);
}
