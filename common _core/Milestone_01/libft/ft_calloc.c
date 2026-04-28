/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:30:45 by cmarques          #+#    #+#             */
/*   Updated: 2026/04/25 20:11:54 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	j;
	char	*new_string;

	j = 0;
	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (size > ((size_t)-1) / nmemb)
	{
		return (NULL);
	}
	new_string = malloc(size * nmemb);
	if (!new_string)
		return (NULL);
	while (j < size * nmemb)
	{
		new_string[j] = 0;
		j++;
	}
	return (new_string);
}
