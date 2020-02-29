/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:17:23 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 16:17:24 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"




int		parse_all_args(t_stacks *st, char *ptr, int *j_addr, int *n_addr)
{
	if (ft_strchr(ptr, ' '))
	{
		while (ptr != NULL && *ptr != '\0')
		{
			ptr = ft_atoi_backsp(ptr, st->a + *j_addr, n_addr);
			if (*n_addr == -1)
				return (free_st_a_overflaw(st));
			(*j_addr)++;
		}
	}
	else
	{
		ptr = ft_atoi_backsp(ptr, st->a + *j_addr, n_addr);
		if (*n_addr == -1)
			return (free_st_a_overflaw(st));
		(*j_addr)++;
	}
	return (1);
}


/*
** returns amount of numbers in av[i]
*/

int		amount_of_numb_in_one_av(char *str)
{
	int		flag;
	char	*trimi;
	int		amount_in_one;
	int		j;

	if (!(trimi = ft_strtrim(str)))
		return (-1);
	flag = 0;
	amount_in_one = 0;
	j = 0;
	while (trimi[j] != '\0')
	{
		if (trimi[j] == ' ' && flag == 0)
		{
			amount_in_one++;
			flag = 1;
		}
		else if (trimi[j] != ' ' && flag == 1)
			flag = 0;
		j++;
	}
	amount_in_one++;
	free(trimi);
	return (amount_in_one);
}

/*
** returns total amount of numbers
*/

int		amount_of_numb(int ac, char **av, int start_av)
{
	int		i;
	int		curr;
	int		amount;

	i = start_av;
	amount = 0;
	while (i < ac)
	{
		if ((curr = amount_of_numb_in_one_av(av[i])) != -1)
			amount += curr;
		else
			return (-1);
		i++;
	}
	return (amount);
}
