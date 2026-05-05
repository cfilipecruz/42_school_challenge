/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:05:46 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:44:07 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	str = (const char *)s;
	while (n != 0)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
		n--;
	}
	if (*str == (unsigned char)c)
		return ((unsigned char *)str);
	return (NULL);
}
