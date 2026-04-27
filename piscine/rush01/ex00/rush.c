/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:34:12 by mde-alme          #+#    #+#             */
/*   Updated: 2026/02/08 16:55:43 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		is_visible(int *line);
int		check_row(int *numbers, int **sol, int row);
int		check_col(int *numbers, int **sol, int col);
int		is_possible(int row, int col, int val, int **sol);

void	print_square(int **sol)
{
	int		i;
	int		j;
	char	l;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			l = sol[i][j] + '0';
			write(1, &l, 1);
			if (j < 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	*convert_numbers(char *str)
{
	int	*numbers;
	int	total;
	int	i;
	int	j;

	total = 16;
	i = 0;
	j = 0;
	numbers = (int *)malloc(total * sizeof(*numbers));
	while (str[i])
	{
		if (((i % 2 == 1) && str[i] != ' ') || ((i % 2 == 0) && (!(str[i] >= '1'
						&& str[i] <= '4'))))
			return (write(1, "Error\n", 6), free(numbers), NULL);
		if (str[i] >= '1' && str[i] <= '4')
		{
			numbers[j++] = str[i] - '0';
			if (j > 16)
				return (write(1, "Error\n", 6), free(numbers), NULL);
		}
		i++;
	}
	if (j < 16)
		return (write(1, "Error\n", 6), free(numbers), NULL);
	return (numbers);
}

int	solution(int *numbers, int pos, int **sol)
{
	int	val;

	if (pos == 16)
	{
		print_square(sol);
		return (1);
	}
	val = 1;
	while (val <= 4)
	{
		if (is_possible(pos / 4, pos % 4, val, sol))
		{
			sol[pos / 4][pos % 4] = val;
			if ((pos % 4 == 3 && !check_row(numbers, sol, pos / 4)) || ((pos
						/ 4) == 3 && !check_col(numbers, sol, pos % 4)))
				sol[pos / 4][pos % 4] = 0;
			else if (solution(numbers, pos + 1, sol))
				return (1);
			else
				sol[pos / 4][pos % 4] = 0;
		}
		val++;
	}
	return (0);
}

int	**grid_setup(void)
{
	int	i;
	int	j;
	int	**sol;

	i = 0;
	j = 0;
	sol = (int **)malloc(4 * sizeof(int *));
	while (i < 4)
	{
		sol[i] = (int *)malloc(4 * sizeof(int));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			sol[i][j] = 0;
			j++;
		}
		i++;
	}
	return (sol);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int	**sol;
	int	i;
	int	s;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	numbers = convert_numbers(argv[1]);
	if (!numbers)
		return (1);
	sol = grid_setup();
	if (solution(numbers, 0, sol) == 0)
		write(1, "Error\n", 6);
	free(numbers);
	while (i < 4)
	{
		free(sol[i]);
		i++;
	}
	free(sol);
	return (0);
}
