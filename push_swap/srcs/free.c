/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:33:51 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:33:52 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*stack)
	{
		tmp1 = *stack;
		tmp2 = tmp1->next;
		while (tmp1)
		{
			tmp1->next = NULL;
			tmp1->prev = NULL;
			free(tmp1);
			tmp1 = tmp2;
			if (tmp2)
				tmp2 = tmp2->next;
		}
		*stack = NULL;
	}
}

static void	free_result(t_command **res)
{
	t_command	*tmp1;
	t_command	*tmp2;

	if (*res)
	{
		tmp1 = *res;
		tmp2 = tmp1->next;
		while (tmp1)
		{
			free(tmp1->command);
			tmp1->command = NULL;
			tmp1->next = NULL;
			tmp1->prev = NULL;
			free(tmp1);
			tmp1 = tmp2;
			if (tmp2)
				tmp2 = tmp2->next;
		}
		*res = NULL;
	}
}

void	free_arr_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		arr[i] = NULL;
		i++;
	}
	free (arr);
	arr = NULL;
}

void	free_main(t_main *main)
{
	if (main)
	{
		free_stack(&(main->a));
		free_stack(&(main->b));
		free_result(&(main->res));
		free_arr_char(main->arr_char);
		free(main);
		main = NULL;
	}
}
