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
** we found a number inside av_i.
** if there is sth bad afterwards, then return 0
** if av_i is ok in terms of digits, return 1
*/

int		inside_number_bad(char *av_i)
{
	char	*p;
	int		j;

	j = 0;
	p = av_i + 1;
	while (*p)
	{
		p = ft_strchr(p, '-');
		if (p == NULL)
			break ;
		if (p[-1] != ' ' || p[1] == '\0' || (p[-1] == ' ' && p[1] == ' '))
			return (0);
		p++;
	}
	p = av_i + 1;
	while (*p)
	{
		p = ft_strchr(p, '+');
		if (p == NULL)
			break ;
		if (p[-1] != ' ' || p[1] == '\0' || (p[-1] == ' ' && p[1] == ' '))
			return (0);
		p++;
	}
	return (1);
}

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
	// ft_printf("i = %d\n", i);
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
		if (inside_number_bad(av[i]) == 0)
			return (0);
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
