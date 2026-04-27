/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:12:17 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/03 20:00:15 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strtolower(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i = i + 1;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strtolower(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0
			|| !((str[i - 1] >= 'a' && str[i - 1] <= 'z')
				|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 32;
			}
		}
		i = i + 1;
	}
	return (str);
}
