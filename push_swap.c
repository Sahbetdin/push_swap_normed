/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:59:03 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 16:59:05 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	set_start_arg(t_stacks *st, char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'c')
		st->start_arg = 2;
	else
		st->start_arg = 1;
}

int		check_b_allocation(t_stacks *st, int *srt)
{
	if (if_allocated_b(st) == 0)
	{
		free(srt);
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int			res;
	t_stacks	st;
	int			*sorted;
	t_info		*pc;
	int			*num;

	if (ac == 1)
		return (0);
	set_start_arg(&st, av);
	res = set_st_a(ac, av, &st, &sorted);
	if (bad_input(res) == 0)
		return (0);
	if (check_b_allocation(&st, sorted) == 0)
		return (0);
	if (malloc_pc(&st, &pc) == 0)
		return (0);
	if (!(num = (int *)malloc(sizeof(int) * 8)))
		return (0);
	while (check_stacks(&st) == 0)
		process_stacks(&st, pc, sorted, num);
	if (av[1][0] == '-' && ft_strchr((const char *)av[1], 'c'))
		ft_printf("number of oparations is %d\n", st.oper);
	free_stacks_after_success(&st, pc, sorted, num);
	return (0);
}
