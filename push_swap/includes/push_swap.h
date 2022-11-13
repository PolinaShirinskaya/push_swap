/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:35:54 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:36:05 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_command
{
	char				*command;
	struct s_command	*next;
	struct s_command	*prev;
}					t_command;

typedef struct s_main
{
	t_stack		*a;
	t_stack		*b;
	t_command	*res;
	char		**arr_char;
}					t_main;

t_main		*create_stacks(void);
char		**parsing_input_data(int argc, char **argv, t_main *main);
int			validation_input_data(int len, char **arr);
t_stack		*create_stack_a(t_main *main);
t_command	*create_new_result(t_main *main);
void		update_output_result(t_main *main);
char		*get_result(t_main *main);

void		free_main(t_main *main);
void		free_arr_char(char **arr);
void		free_stack(t_stack **stack);

void		command(t_main *main, char const *str);
void		write_command(t_main *main, char const *str, int done);

int			sa_sb(t_stack **stack);
int			ss(t_stack **stack_a, t_stack **stack_b);
int			pa_pb(t_stack **stack_from, t_stack **stack_to);
int			ra_rb(t_stack **stack);
int			rr(t_stack **stack_a, t_stack **stack_b);
int			rra_rrb(t_stack **stack);
int			rrr(t_stack **stack_a, t_stack **stack_b);

void		private_sort(t_main *inf);

int			len_stack(t_stack **stack);
int			find_min_value(t_stack **stack);
int			find_max_value(t_stack **stack);
int			find_index(t_stack **stack, int index);
t_stack		*end_stack(t_stack **stack);

int			check_sort_input_data(char **arr);
int			len_arr_str(char **arr);
int			error(char *str, t_main *inf);
void		print_result(char *res);

void		radix(t_main *main);
void		sec_radix(t_main *main, int max_bits, int size);

#endif