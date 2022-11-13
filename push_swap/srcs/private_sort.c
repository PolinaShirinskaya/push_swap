/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:34:05 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:34:06 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	sort_3_types(int a, int b, int c)
{
	int	type;

	type = 0;
	if (a > b && b > c && a > c)
		type = 1;
	else if (a > b && b < c && a > c)
		type = 2;
	else if (a > b && b < c && a < c)
		type = 3;
	else if (a < b && b > c && a > c)
		type = 4;
	else if (a < b && b > c && a < c)
		type = 5;
	return (type);
}

static void	private_sort_3(t_main *main)
{
	int	type;

	type = sort_3_types(main->a->index, \
	main->a->next->index, main->a->next->next->index);
	if (type == 1)
	{
		command(main, "sa");
		command(main, "rra");
	}
	else if (type == 2)
		command(main, "ra");
	else if (type == 3)
		command(main, "sa");
	else if (type == 4)
		command(main, "rra");
	else if (type == 5)
	{
		command(main, "sa");
		command(main, "ra");
	}
}

static void	private_sort_4(t_main *main)
{
	while (main->a->index != find_min_value(&(main->a)))
	{
		if (find_index(&(main->a), find_min_value(&(main->a))) <= 2)
			command(main, "sa");
		else if (find_index(&(main->a), find_min_value(&(main->a))) > 2)
			command(main, "rra");
	}
	command(main, "pb");
	private_sort_3(main);
	command(main, "pa");
}

static void	private_sort_5(t_main *main)
{
	while (main->a->index != find_min_value(&(main->a)))
	{
		if (find_index(&(main->a), find_min_value(&(main->a))) <= 2)
			command(main, "sa");
		else if (find_index(&(main->a), find_min_value(&(main->a))) == 3)
			command(main, "ra");
		else if (find_index(&(main->a), find_min_value(&(main->a))) >= 4)
			command(main, "rra");
	}
	command(main, "pb");
	private_sort_4(main);
	command(main, "pa");
}

void	private_sort(t_main *main)
{
	if (len_stack(&(main->a)) == 2)
	{
		if (main->a->index > main->a->next->index)
			command(main, "sa");
	}
	else if (len_stack(&(main->a)) == 3)
		private_sort_3(main);
	else if (len_stack(&(main->a)) == 4)
		private_sort_4(main);
	else if (len_stack(&(main->a)) == 5)
		private_sort_5(main);
}
