/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:24:17 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/19 14:02:26 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strslen(char **strs, int size)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	ft_seplen(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

char	*ft_strcat(int size, char **strs, char *join, char *sep)
{
	int	j;
	int	a;
	int	anothercounter;
	int	i;

	a = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
			join[a++] = strs[i][j++];
		if (i != size - 1)
		{
			anothercounter = 0;
			while (sep[anothercounter])
				join[a++] = sep[anothercounter++];
		}
		i++;
	}
	join[a] = '\0';
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		counter;
	char	*join;
	char	*s;
	int		sepcounter;
	char	*result;

	if (size < 1)
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		s[0] = '\0';
		return (s);
	}
	counter = ft_strslen(strs, size);
	sepcounter = ft_seplen(sep);
	join = (char *)malloc(((counter + (sepcounter * (size - 1))) + 1));
	if (!join)
		return (NULL);
	result = ft_strcat(size, strs, join, sep);
	return (result);
}
/*int	main(void)
{
	char	*strs1[] = {"Hello", "42", "World"};
	char	*strs2[] = {"One"};
	char	*strs3[] = {};
	char	*result;

	result = ft_strjoin(3, strs1, " - ");
	printf("Result 1: \"%s\"\n", result);
	free(result);

	result = ft_strjoin(1, strs2, ", ");
	printf("Result 2: \"%s\"\n", result);
	free(result);

	result = ft_strjoin(0, strs3, ", ");
	printf("Result 3: \"%s\"\n", result);
	free(result);

	return (0);
}*/
