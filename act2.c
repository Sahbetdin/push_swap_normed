/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:50:37 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/28 21:50:41 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int		put_action(t_stacks *st, char *act, int flag)
{
	if (flag == 1)
		ft_putendl(act);
	st->oper++;
	return (1);
}

int		action(t_stacks *st, char *act, int fl)
{
	if (ft_memcmp(act, "sa", 2) == 0)
		swap_in_stack(st, 'A');
	else if (ft_memcmp(act, "sb", 2) == 0)
		swap_in_stack(st, 'B');
	else if (ft_memcmp(act, "ss", 2) == 0)
		swap_both(st);
	else if (ft_memcmp(act, "ra", 2) == 0)
		rotate(st, 'A');
	else if (ft_memcmp(act, "rb", 2) == 0)
		rotate(st, 'B');
	else if (ft_memcmp(act, "rra", 3) == 0)
		reverse_rotate(st, 'A');
	else if (ft_memcmp(act, "rrb", 3) == 0)
		reverse_rotate(st, 'B');
	else if (ft_memcmp(act, "rrr", 3) == 0)
		reverse_rotate_both(st);
	else if (ft_memcmp(act, "rr", 2) == 0)
		rotate_both(st);
	else if (ft_memcmp(act, "pa", 2) == 0)
		push_1_to_2(st, 'B');
	else if (ft_memcmp(act, "pb", 2) == 0)
		push_1_to_2(st, 'A');
	else
		return (0);
	return (put_action(st, act, fl));
}
