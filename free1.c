/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:07:50 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/29 17:07:53 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	free_stacks(t_stacks *st)
{
	free(st->a);
	free(st->b);
}

int		free_st_a_overflaw(t_stacks *st)
{
	free(st->a);
	st->a = NULL;
	return (-2);
}

void	free_stacks_after_success(t_stacks *st, t_info *pc, int *srt, int *num)
{
	free(st->a);
	free(st->b);
	st->a = NULL;
	st->b = NULL;
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
	free(srt);
	srt = NULL;
}
