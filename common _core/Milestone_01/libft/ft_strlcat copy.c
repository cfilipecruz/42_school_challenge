/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:50:31 by cmarques          #+#    #+#             */
/*   Updated: 2026/04/28 15:33:50 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s);

char	*ft_strcat(char *restrict dst, const char *restrict src)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(dst);
	while (src[i])
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	return (dst);
}