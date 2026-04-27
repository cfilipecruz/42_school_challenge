/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:22:55 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/04 10:32:04 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	counter;
	unsigned int	counter2;

	i = 0;
	counter = 0;
	counter2 = 0;
	while (counter < size && dest[counter] != '\0')
	{
		counter++;
	}
	while (src[counter2] != '\0')
	{
		counter2++;
	}
	if (counter >= size)
	{
		return (size + counter2);
	}
	while (src[i] && counter + i < size - 1)
	{
		dest[counter + i] = src[i];
		i++;
	}
	if (counter + i < size)
	{
		dest[counter + i] = '\0';
	}
	return (counter + counter2);
}
