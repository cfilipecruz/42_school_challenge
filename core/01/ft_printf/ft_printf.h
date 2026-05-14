/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:05:28 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/14 18:51:48 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putpoint(void *p);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int u);
int		ft_puthex(unsigned int p, char format);

int		main(void);

size_t	ft_strlen(const char *s);

#endif