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
** checks if av[i] contains at least one digit
*/

int		av_i_has_digit(char *av_i)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (ft_strchr(av_i, j + '0'))
			return (1);
		j++;
	}
	return (0);
}

/*
** returns 0 if non-numerical characters or not-backspace found
** returns -1 for "" or ''
** returns 0 if in av[i] no digit found
** otherwise returns 1
*/

int		check_if_num_backsp(int ac, char **av, int start_av)
{
	int i;
	int j;

	i = start_av;
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
		if (ft_strlen(av[i]) == 0)
			return (-1);
		if (ft_strlen(av[i]) == 1 && (av[i][0] == '-' || av[i][0] == '+'))
			return (-1);
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
			free(*srt);
			*srt = NULL;
			return (-3);
		}
		j++;
	}
	return (1);
}

/*
** if pa is 0 and st->a is sorted, then return 1
** else return 0
*/

int		check_stacks(t_stacks *st)
{
	int i;

	if (st->pa != 0)
		return (0);
	i = 0;
	while (i < st->n - 1)
	{
		if (st->a[i] > st->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
