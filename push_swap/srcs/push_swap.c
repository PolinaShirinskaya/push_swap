/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:34:09 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:34:10 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*push_swap(t_main *main)
{
	main->a = create_stack_a(main);
	if (len_arr_str(main->arr_char) < 6)
		private_sort(main);
	else
		radix(main);
	return (get_result(main));
}

int	main(int argc, char **argv)
{
	t_main	*main;
	int		check;

	if (argc < 2)
		return (0);
	main = create_stacks();
	main->arr_char = parsing_input_data(argc, argv, main);
	check = validation_input_data(len_arr_str(main->arr_char), main->arr_char);
	if (check == 0)
		exit(error("Error; no input arguments\n", main));
	if (check == -1)
		exit(error("Error: input arguments is'n digits\n", main));
	if (check == 1 && check_sort_input_data(main->arr_char))
		exit(error("Error: input string is already sorted\n", main));
	if (check == 1)
	{
		print_result(push_swap(main));
		free_main(main);
	}
	return (0);
}
