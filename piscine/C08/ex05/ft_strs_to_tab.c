/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:31:10 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/10 18:36:22 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*tab;

	i = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	while (i < ac)
	{
		j = 0;
		tab[i].size = 0;
		while (av[i][j])
		{
			tab[i].size++;
			j++;
		}
		tab[i].copy = (char *)malloc((tab[i].size * sizeof(char)) + 1);
		j = 0;
		while (av[i][j])
		{
			tab[i].copy[j] = av[i][j];
			j++;
		}
		tab[i].copy[j] = '\0';
		tab[i].str = malloc((tab[i].size * sizeof(char)) + 1);
		tab[i].str = av[i];
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	t_stock_str	*tab;
	int			i;

	tab = ft_strs_to_tab(argc, argv);
	ft_show_tab(tab);
	return (0);
}*/
