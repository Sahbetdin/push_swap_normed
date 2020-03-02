/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:05:41 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 17:05:43 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

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
	run_gnl(&st);
	if_ok(check_stacks(&st));
	free_stacks_after_checker(&st, sorted);
	return (0);
}
