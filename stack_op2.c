/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:04:46 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/29 17:04:48 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

/*
** push from whatever in c is.
*/

void	push_1_to_2(t_stacks *st, char c)
{
	if (c == 'A' && st->pa < st->n)
	{
		st->b[st->pb] = st->a[st->pa];
		st->pa++;
		st->pb--;
	}
	else if (c == 'B' && st->pb < st->n - 1)
	{
		st->pa--;
		st->pb++;
		st->a[st->pa] = st->b[st->pb];
	}
}

/*
** rotate what in c is
*/

void	rotate(t_stacks *st, char c)
{
	int tmp;
	int i;

	if (c == 'A' && st->pa < st->n - 1)
	{
		tmp = st->a[st->pa];
		i = st->pa - 1;
		while (++i < st->n - 1)
			st->a[i] = st->a[i + 1];
		st->a[i] = tmp;
	}
	else if (c == 'B' && st->pb < st->n - 2)
	{
		tmp = st->b[st->pb + 1];
		i = st->pb;
		while (++i < st->n - 1)
			st->b[i] = st->b[i + 1];
		st->b[i] = tmp;
	}
}

void	reverse_rotate(t_stacks *st, char c)
{
	int tmp;
	int i;

	i = st->n - 1;
	if (c == 'A' && st->pa < st->n - 1)
	{
		tmp = st->a[i];
		while (i > st->pa)
		{
			st->a[i] = st->a[i - 1];
			i--;
		}
		st->a[st->pa] = tmp;
	}
	else if (c == 'B' && st->pb < st->n - 2)
	{
		tmp = st->b[i];
		while (i > st->pb + 1)
		{
			st->b[i] = st->b[i - 1];
			i--;
		}
		st->b[st->pb + 1] = tmp;
	}
}

int		validate_action(char *s)
{
	if (
	((ft_memcmp(s, "sa", 2) == 0 || ft_memcmp(s, "sb", 2) == 0 ||
	ft_memcmp(s, "ss", 2) == 0 || ft_memcmp(s, "ra", 2) == 0 ||
	ft_memcmp(s, "rb", 2) == 0 || ft_memcmp(s, "rr", 2) == 0 ||
	ft_memcmp(s, "pa", 2) == 0 || ft_memcmp(s, "pb", 2) == 0) &&
	ft_strlen(s) == 2) || ((ft_memcmp(s, "rrb", 3) == 0 ||
	ft_memcmp(s, "rrr", 3) == 0 || ft_memcmp(s, "rra", 3) == 0) &&
	ft_strlen(s) == 3))
		return (1);
	return (0);
}
