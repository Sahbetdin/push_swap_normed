/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:40:56 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/29 16:41:01 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

/*
** this function should have been present in
** process_stacks.
*/

int		if_sort_5_alone(t_stacks *st, int *srt, int *num)
{
	int i;

	if (st->n == 5)
	{
		sort_5(st, srt);
		return (0);
	}
	i = -1;
	while (++i < 8)
		num[i] = 0;
	return (1);
}

void	sort_5(t_stacks *st, int *srt)
{
	if (st->a[st->pa + 1] == srt[0])
		action(st, "sa", 1);
	else if (st->a[st->pa + 2] == srt[0])
	{
		action(st, "ra", 1);
		action(st, "ra", 1);
	}
	else if (st->a[st->pa + 3] == srt[0])
	{
		action(st, "rra", 1);
		action(st, "rra", 1);
	}
	else if (st->a[st->pa + 4] == srt[0])
		action(st, "rra", 1);
	if (st->a[st->pa] == srt[0] && check_stacks(st) == 0)
	{
		action(st, "pb", 1);
		sort_4_alone(st, srt + 1);
		action(st, "pa", 1);
	}
}
