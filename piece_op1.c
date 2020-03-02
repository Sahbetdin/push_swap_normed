/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:59:39 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/29 16:59:41 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int		malloc_pc(t_stacks *st, t_info **pc)
{
	int			n;
	int			i;

	n = 200;
	if (!(*pc = (t_info *)malloc(sizeof(t_info) * 200)))
		return (0);
	i = 0;
	while (i < 199)
	{
		(*pc)[i].begin = 0;
		(*pc)[i].end = 0;
		(*pc)[i].amount = 0;
		(*pc)[i].lt = 0;
		i++;
	}
	set_first_info(*pc, st->n);
	set_pc_remaining(*pc);
	return (1);
}

void	set_first_info(t_info *pc, int n)
{
	pc += 1;
	pc->begin = 0;
	pc->end = n;
	pc->amount = pc->end - pc->begin;
	pc->lt = 'A';
}

void	set_pc_remaining(t_info *pc)
{
	int			i;

	i = 2;
	while (i < 199)
	{
		pc[i].amount = 0;
		i++;
	}
}

void	divide_piece_info(t_info *pc, int flag1)
{
	int		mid;
	t_info	*old;

	old = pc;
	pc++;
	mid = (old->begin + old->end) / 2;
	if (flag1 == 1 && old->lt == 'A')
		pc->lt = 'B';
	else if (flag1 == 1 && old->lt == 'B')
		pc->lt = 'A';
	else if (flag1 == 0 && old->lt == 'A')
		pc->lt = 'A';
	else if (flag1 == 0 && old->lt == 'B')
		pc->lt = 'B';
	pc->begin = old->begin;
	pc->end = mid;
	pc->amount = pc->end - pc->begin;
	old->begin = mid;
	old->amount = old->end - old->begin;
}

/*
** begin increases by delta
** amount decreases by delta
*/

void	change_piece_beg_am(t_info *pc0, int delta)
{
	pc0->begin += delta;
	pc0->amount -= delta;
}
