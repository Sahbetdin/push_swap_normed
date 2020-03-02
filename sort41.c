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
	else if (st->a[st->pa + 2] == srt[0])
	{
		action(st, "ra", 1);
		action(st, "ra", 1);
	}
	if (st->a[st->pa] == srt[0] && check_stacks(st) == 0)
	{
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

void	sort_4_a(t_stacks *st, t_info *pc0, int *srt)
{
	int flag;

	flag = 0;
	if (st->a[st->pa + 1] == srt[pc0->begin])
		action(st, "sa", 1);
	if (st->a[st->pa] == srt[pc0->begin])
	{
		action(st, "ra", 1);
		flag = 10;
	}
	else if (st->a[st->pa + 2] == srt[pc0->begin])
		sort_4_st_pa_2(st, pc0, srt);
	else if (st->a[st->pa + 3] == srt[pc0->begin])
		sort_4_st_pa_3(st, pc0, srt, &flag);
	if (flag == 10)
	{
		change_piece_beg_am(pc0, 1);
		sort_3_elements(st, pc0, srt);
	}
	else if (flag == 20)
	{
		change_piece_beg_am(pc0, 2);
		sort_2_elements(st, pc0);
	}
}

void	sort_4_elements(t_stacks *st, t_info *pc0, int *srt)
{
	int k;

	k = 0;
	if (pc0->lt == 'A' && pc0->amount + st->pa == st->n)
		sort_4_alone(st, srt);
	else if (pc0->lt == 'A')
		sort_4_a(st, pc0, srt);
	else if (pc0->lt == 'B')
	{
		if (st->b[st->pb + 2] == srt[pc0->begin])
			action(st, "sb", 1);
		if (st->b[st->pb + 1] == srt[pc0->begin])
		{
			pa_ra(st);
			change_piece_beg_am(pc0, 1);
			sort_3_elements(st, pc0, srt);
		}
		else if (st->b[st->pb + 3] == srt[pc0->begin])
			sort_4_st_pb_3(st, pc0, srt);
		else if (st->b[st->pb + 4] == srt[pc0->begin])
			sort_4_st_pb_4(st, pc0, srt);
	}
	zerofy_piece(pc0);
}
