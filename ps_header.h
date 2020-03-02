/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:37:51 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 19:37:54 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HEADER_H
# define PS_HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include "./my_libft/libft.h"
# define INT_MAX 2147483647

typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			pa;
	int			pb;
	int			n;
	int			oper;
	int			start_arg;
}				t_stacks;

typedef struct	s_info
{
	int			begin;
	int			end;
	int			amount;
	char		lt;
}				t_info;

/*
** check_conditions.c
*/

int				av_i_has_digit(char *av_i);
int				check_if_num_backsp(int ac, char **av, int start_av);
int				check_if_dupl(t_stacks *st, int **srt);
int				check_stacks(t_stacks *st);

/*
** free1.c
*/

void			free_stacks(t_stacks *st);
int				free_st_a_overflaw(t_stacks *st);
void			free_stacks_after_success(t_stacks *st, t_info *pc, \
				int *srt, int *num);
void			free_stacks_after_checker(t_stacks *st, int *srt);

/*
** ft_atoi_backsp.c
*/

int				*cycle_in_atoi_backsp(const char *str, int *a_r, int *n, \
				int *a_i);
int				str_end_in_atoi_backsp(const char *str_i, int *n);
char			*ft_atoi_backsp(const char *str, int *p_numb, int *n);

/*
** fun_print.c
*/

void			print_piece(t_info piece0);
void			print_arrays(t_stacks *st);
void			print_sorted(int *srt, int n);

/*
** funs1.c
*/

void			ft_swap(int *a, int *b);
int				*sort_array(int *arr, int n);
int				*make_me_sorted(t_stacks *st);
void			if_ok(int i);

/*
** parse1.c
*/

int				amount_of_numb_in_one_av(char *str);
int				amount_of_numb(int ac, char **av, int start_av);
int				parse_all_args(t_stacks *st, char *ptr, int *j_addr, \
				int *n_addr);
int				bad_input(int res);
int				if_allocated_b(t_stacks *st);

/*
** piece_op1.c
*/

int				malloc_pc(t_stacks *st, t_info **pc);
void			set_first_info(t_info *pc, int n);
void			set_pc_remaining(t_info *pc);
void			divide_piece_info(t_info *pc, int flag1);
void			change_piece_beg_am(t_info *pc0, int delta);

/*
** set.c
*/

void			set_arr_to_zero(int *b, int n);
int				parse_complicated(int ac, char **av, t_stacks *st);
int				set_st_a(int ac, char **av, t_stacks *st, int **sorted);
int				set_st_b(t_stacks *st);

/*
** sort2.c
*/

void			sort_2_not_alone(t_stacks *st, t_info *pc0);
void			sort_2_elements(t_stacks *st, t_info *pc0);

/*
** sort3.c
*/

void			sort_top_top(t_stacks *st);
void			sort_3_a_alone(t_stacks *st, int *srt);
void			sort_3_a_not_alone(t_stacks *st, t_info *pc0, int *srt);
void			sort_3_b(t_stacks *st, t_info *pc0, int *srt);
void			sort_3_elements(t_stacks *st, t_info *pc0, int *srt);

/*
** sort41.c
*/

void			sort_4_a(t_stacks *st, t_info *pc0, int *srt);
void			sort_4_elements(t_stacks *st, t_info *pc0, int *srt);
void			zerofy_piece(t_info *pc0);
void			sort_4_alone(t_stacks *st, int *srt);
void			sort_3_for_4(t_stacks *st, int min2);

/*
** sort42.c
*/

void			sort_1_1(t_stacks *st, t_info *pc0, int *srt);
void			sort_4_st_pb_4(t_stacks *st, t_info *pc0, int *srt);
void			sort_4_st_pa_2(t_stacks *st, t_info *pc0, int *srt);
void			sort_4_st_pa_3(t_stacks *st, t_info *pc0, int *srt, \
				int *addr_flag);
void			sort_4_st_pb_3(t_stacks *st, t_info *pc0, int *srt);

/*
** sort5.c
*/

int				if_sort_5_alone(t_stacks *st, int *srt, int *num);
void			sort_5(t_stacks *st, int *srt);

/*
** stack_op0.c
*/

void			ra_2(t_stacks *st);
void			pa_2(t_stacks *st);
void			pa_ra(t_stacks *st);
void			sa_ra(t_stacks *st);
void			sa_rra(t_stacks *st);

/*
** stack_op1.c
*/

int				put_action(t_stacks *st, char *act, int flag);
int				action(t_stacks *st, char *act, int fl);
int				active_piece(t_info *pc);
void			rra_sa(t_stacks *st);
void			pb_2(t_stacks *st);

/*
** stack_op2.c
*/

void			push_1_to_2(t_stacks *st, char c);
void			rotate(t_stacks *st, char c);
void			reverse_rotate(t_stacks *st, char c);
int				validate_action(char *s);

/*
** stack_op3.c
*/

void			swap_in_stack(t_stacks *st, char c);
void			swap_both(t_stacks *st);
void			rotate_both(t_stacks *st);
void			reverse_rotate_both(t_stacks *st);

/*
** stack_op4.c
*/

int				is_pb(t_stacks *st, t_info *pc0, int *srt, int fl);
void			check_first_element(t_stacks *st, t_info *pc0, int *sorted);
void			rotate_back_stacks(t_stacks *st, t_info *pc_i, \
				int rot_cnt, int flag);
void			run_gnl(t_stacks *st);

/*
** stack_op5.c
*/

void			process_more_than_4_a(t_stacks *st, t_info *pc_i, \
				int *srt, int *num);
void			process_cycle(t_stacks *st, t_info *pc_i, int *sorted, \
				int *num);
void			check_if_b_empty(t_info *pc_i_1, int *num);
void			sort_234(t_stacks *st, t_info *pc_i, int *sorted);
void			process_stacks(t_stacks *st, t_info *pc, int *sorted, int *num);
#endif
