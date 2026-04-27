/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:43:10 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/17 12:00:38 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	if (size >= 2)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				i = 0;
			}
			else
			{
				i++;
			}
		}
	}
}
/*
void	print_array(int *tab, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
}

int	main(void)
{
	// ---------- Test 1: Small positive numbers
	int tab1[] = {3, 1, 2};
	int size1 = 3;
	printf("Test 1 - Before: "); print_array(tab1, size1);
	ft_sort_int_tab(tab1, size1);
	printf("Test 1 - After:  "); print_array(tab1, size1);
	printf("\n");

	// ---------- Test 2: Already sorted
	int tab2[] = {1, 2, 3, 4, 5};
	int size2 = 5;
	printf("Test 2 - Before: "); print_array(tab2, size2);
	ft_sort_int_tab(tab2, size2);
	printf("Test 2 - After:  "); print_array(tab2, size2);
	printf("\n");

	// ---------- Test 3: Reverse order
	int tab3[] = {5, 4, 3, 2, 1};
	int size3 = 5;
	printf("Test 3 - Before: "); print_array(tab3, size3);
	ft_sort_int_tab(tab3, size3);
	printf("Test 3 - After:  "); print_array(tab3, size3);
	printf("\n");

	// ---------- Test 4: Negative numbers
	int tab4[] = {-5, 3, -2, 0, 1};
	int size4 = 5;
	printf("Test 4 - Before: "); print_array(tab4, size4);
	ft_sort_int_tab(tab4, size4);
	printf("Test 4 - After:  "); print_array(tab4, size4);
	printf("\n");

	// ---------- Test 5: Large array with duplicates
	int tab5[] = {10, -1, 7, 10, 0, -1, 3};
	int size5 = 7;
	printf("Test 5 - Before: "); print_array(tab5, size5);
	ft_sort_int_tab(tab5, size5);
	printf("Test 5 - After:  "); print_array(tab5, size5);
	printf("\n");

	// ---------- Test 6: Single element
	int tab6[] = {42};
	int size6 = 1;
	printf("Test 6 - Before: "); print_array(tab6, size6);
	ft_sort_int_tab(tab6, size6);
	printf("Test 6 - After:  "); print_array(tab6, size6);
	printf("\n");

	// ---------- Test 7: Empty array
	int tab7[0];
	int size7 = 0;
	printf("Test 7 - Before: "); print_array(tab7, size7);
	ft_sort_int_tab(tab7, size7);
	printf("Test 7 - After:  "); print_array(tab7, size7);
	printf("\n");

	return (0);
}*/
