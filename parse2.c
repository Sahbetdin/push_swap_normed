/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:04:58 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 17:05:00 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	free_stacks_after_success(t_stacks *st, t_info *pc, int *srt, int *num)
{
	free(st->a);
	free(st->b);
	st->a = NULL;
	st->b = NULL;
	free(st);
	st = NULL;
	free(srt);
	srt = NULL;
	free(num);
	num = NULL;
	free(pc);
	pc = NULL;
}

void	free_stacks_after_checker(t_stacks *st, int *srt)
{
	free(st->a);
	free(st->b);
	st->a = NULL;
	st->b = NULL;
	free(st);
	st = NULL;
	free(srt);
	srt = NULL;
}

int		bad_input(int res)
{
	int g;

	g = 0;
	if (res == 0)
		ft_printf("Malloc error in 'a'\n");
	else if (res == -1)
		ft_printf("Error\n");
	else if (res == -2)
		ft_printf("Error\n");
	else if (res == -3)
		ft_printf("Error\n");
	else if (res == -4)
		ft_printf("Error\n");
	if (res == 0 || res == -1 || res == -2 || res == -3 || res == -4)
		return (0);
	return (1);
}

int		if_allocated_b(t_stacks *st)
{
	int res;

	res = set_st_b(st);
	if (res == 0)
	{
		ft_printf("Malloc error in 'b'\n");
		st->b = NULL;
		free(st->a);
		st->a = NULL;
		free(st);
		free(st);
		st = NULL;
		return (0);
	}
	return (1);
}
