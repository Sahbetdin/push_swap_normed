/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:49:18 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/25 20:49:20 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

/*
** returns 0 if non-numerical characters or not-backspace found
** otherwise returns 1
*/

int		check_if_num_backsp(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' ' ||
			av[i][j] == '-' || av[i][j] == '+'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
** check for duplicates in input
** if duplicates found return -3
** otherwise, if all is good return 1
*/

int		check_if_dupl(t_stacks *st, int **srt)
{
	int	j;

	*srt = make_me_sorted(st);
	j = 0;
	while (j < st->n - 1)
	{
		if ((*srt)[j] == (*srt)[j + 1])
		{
			free(st->a);
			st->a = NULL;
			free(st);
			st = NULL;
			free(*srt);
			*srt = NULL;
			return (-3);
		}
		j++;
	}
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
