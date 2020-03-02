/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funs1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:52:49 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/12 16:52:50 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
** insertion sort algorithm
*/

int		*sort_array(int *arr, int n)
{
	int i;
	int j;

	j = 0;
	while (j < n)
	{
		i = j + 1;
		while (i < n)
		{
			if (arr[i] < arr[j])
				ft_swap(arr + i, arr + j);
			i++;
		}
		j++;
	}
	return (arr);
}

int		*make_me_sorted(t_stacks *st)
{
	int		*sorted;
	int		i;

	sorted = (int *)malloc(sizeof(int) * st->n);
	i = -1;
	while (++i < st->n)
		sorted[i] = st->a[i];
	sort_array(sorted, st->n);
	return (sorted);
}

void	if_ok(int i)
{
	if (i == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
