/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:41:33 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:45:08 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;

	i = 0;
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (len > i)
	{
		new_string[i] = s[i + start];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
