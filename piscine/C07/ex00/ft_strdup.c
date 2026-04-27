/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:35:19 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/09 18:20:19 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*new_string;

	i = 0;
	j = 0;
	while (src[i])
	{
		i++;
	}
	new_string = malloc((i + 1) * sizeof(char));
	while (src[j])
	{
		new_string[j] = src[j];
		j++;
	}
	new_string[j] = '\0';
	return (new_string);
}
