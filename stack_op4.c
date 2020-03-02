/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:05:11 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/29 17:05:15 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

/*
** is pushed to B
*/

int		is_pb(t_stacks *st, t_info *pc0, int *srt, int fl)
{
	int tmp;
	int res;

	res = 0;
	tmp = st->a[st->pa];
	if ((fl && tmp >= srt[pc0[2].begin] && tmp < srt[pc0[1].end]) ||
	(!fl && tmp >= srt[pc0[1].begin] && tmp < srt[pc0[1].end]))
		res = 1;
	return (res);
}

void	check_first_element(t_stacks *st, t_info *pc0, int *sorted)
{
	if (pc0->lt == 'A' && st->a[st->pa] == sorted[pc0->begin] && st->pa +
		pc0->amount != st->n)
	{
		action(st, "ra", 1);
		pc0->begin++;
		pc0->amount--;
	}
}

void	rotate_back_stacks(t_stacks *st, t_info *pc_i, int rot_cnt, int flag)
{
	while (rot_cnt > 0 && flag == 1)
	{
		if (pc_i->lt == 'A')
			action(st, "rra", 1);
		else if (pc_i->lt == 'B')
			action(st, "rrb", 1);
		rot_cnt--;
	}
}

void	run_gnl(t_stacks *st)
{
	char	*s;
	int		res;

	while (get_next_line(0, &s) > 0)
	{
		if (validate_action(s) == 0)
		{
			ft_printf("Error in input. Try again.\n");
			free(s);
			continue ;
		}
		res = action(st, s, 0);
		free(s);
	}
	free(s);
}
