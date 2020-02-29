/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:24:14 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/29 15:24:25 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	run_gnl_in_visual(t_stacks *st)
{
	char		*s;
	int			res;

	while (get_next_line(0, &s) > 0)
	{
		res = action(st, s, 0);
		free(s);
		system("clear");
		print_arrays(st);
		system("sleep 0.5");
	}
	free(s);
}

int		main(int ac, char **av)
{
	t_stacks	st;
	int			*sorted;
	int			res;

	if (ac == 1)
		return (0);
	if (av[1][0] == '-' && av[1][1] == 'c')
		st.start_arg = 2;
	else
		st.start_arg = 1;
	res = set_st_a(ac, av, &st, &sorted);
	if (bad_input(res) == 0)
		return (0);
	if (if_allocated_b(&st) == 0)
	{
		free(sorted);
		return (0);
	}
	run_gnl_in_visual(&st);
	free_stacks_after_checker(&st, sorted);
	return (0);
}
