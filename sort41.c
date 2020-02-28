/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort41.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:44:19 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 14:44:25 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	rra_sa(t_stacks *st)
{
	action(st, "rra", 1);
	action(st, "sa", 1);
}

void	pb_2(t_stacks *st)
{
	action(st, "pb", 1);
	action(st, "pb", 1);
}

void	zerofy_piece(t_info *pc0)
{
	pc0->lt = 0;
	pc0->begin = 0;
	pc0->end = 0;
	pc0->amount = 0;
}

void	sort_4_alone(t_stacks *st, int *srt)
{
	if (st->a[st->pa + 1] == srt[0])
		action(st, "sa", 1);
	else if (st->a[st->pa + 3] == srt[0])
		action(st, "rra", 1);
	if (st->a[st->pa] == srt[0] && check_stacks(st) == 0)
	{
		action(st, "pb", 1);
		sort_3_a_alone(st, srt + 1);
		action(st, "pa", 1);
	}
	else if (st->a[st->pa + 2] == srt[0])
	{
		action(st, "ra", 1);
		action(st, "ra", 1);
		action(st, "pb", 1);
		sort_3_a_alone(st, srt + 1);
		action(st, "pa", 1);
	}
}

void	sort_3_for_4(t_stacks *st, int min2)
{
	if (st->a[st->pa + 1] == min2)
		action(st, "sa", 1);
	if (st->a[st->pa] == min2)
	{
		action(st, "ra", 1);
		if (st->a[st->pa] > st->a[st->pa + 1])
			action(st, "sa", 1);
		action(st, "rra", 1);
	}
	else if (st->a[st->pa + 1] == min2 && st->a[st->pa] < st->a[st->pa + 2])
	{
		sa_ra(st);
		sa_rra(st);
	}
	else if (st->a[st->pa + 2] == min2 && st->a[st->pa] > st->a[st->pa + 1])
		action(st, "sa", 1);
	if (st->a[st->pa + 2] == min2)
	{
		action(st, "ra", 1);
		sa_rra(st);
		action(st, "sa", 1);
	}
}
