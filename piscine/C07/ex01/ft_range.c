/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 22:18:34 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/09 18:10:46 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*int_array;
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = min;
	if (min >= max)
		return (NULL);
	while (temp < max)
	{
		temp++;
		i++;
	}
	int_array = malloc((i) * sizeof(int));
	j = 0;
	while (min < max)
	{
		int_array[j] = min;
		min++;
		j++;
	}
	return (int_array);
}
