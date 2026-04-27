/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:36:49 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/07 21:43:45 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	is_visible(int *line)
{
	int	vis;
	int	c;
	int	max;

	vis = 0;
	c = 0;
	max = 0;
	while (c < 4)
	{
		if (line[c] > max)
		{
			max = line[c];
			vis++;
		}
		c++;
	}
	return (vis);
}

int	check_row(int *numbers, int **sol, int row)
{
	int	c;
	int	line[4];

	c = 0;
	while (c < 4)
	{
		line[c] = sol[row][c];
		c++;
	}
	if (numbers[row + 8] != is_visible(line))
	{
		return (0);
	}
	c = 0;
	while (c < 4)
	{
		line[c] = sol[row][3 - c];
		c++;
	}
	if (numbers[row + 12] != is_visible(line))
	{
		return (0);
	}
	return (1);
}

int	check_col(int *numbers, int **sol, int col)
{
	int	c;
	int	line[4];

	c = 0;
	while (c < 4)
	{
		line[c] = sol[c][col];
		c++;
	}
	if (numbers[col] != is_visible(line))
	{
		return (0);
	}
	c = 0;
	while (c < 4)
	{
		line[c] = sol[3 - c][col];
		c++;
	}
	if (numbers[col + 4] != is_visible(line))
	{
		return (0);
	}
	return (1);
}

int	is_possible(int row, int col, int val, int **sol)
{
	int	c;

	c = 0;
	while (c < 4)
	{
		if (sol[row][c] == val || sol[c][col] == val)
			return (0);
		c++;
	}
	return (1);
}
