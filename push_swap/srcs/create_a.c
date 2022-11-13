/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:33:37 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:33:38 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*sort_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (i < len)
	{
		j = len - 1;
		while (j > i)
		{
			if (arr[j - 1] > arr[j])
			{
				n = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = n;
			}
			j--;
		}
		i++;
	}
	return (arr);
}

static int	*make_arr_int(t_main *main)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * len_arr_str(main->arr_char));
	if (!array)
		return (NULL);
	i = 0;
	while (main->arr_char[i])
	{
		array[i] = ft_atoi(main->arr_char[i]);
		i++;
	}
	array = sort_arr(array, len_arr_str(main->arr_char));
	return (array);
}

static t_stack	*index_stack_a(t_stack **stack, int *arr, t_main *main)
{
	t_stack	*tmp;
	int		i;

	if (!arr)
	{
		free_stack(stack);
		free (arr);
		exit (error("Error: malloc 'stack A'\n", main));
	}
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (tmp->value == arr[i])
		{
			tmp->index = i + 1;
			tmp = tmp->next;
			i = 0;
		}
		else
			i++;
	}
	free (arr);
	return (*stack);
}

static t_stack	*init_new_stack(t_main *main)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(error("Error: malloc 'stack A'\n", main));
	new->value = 0;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*create_stack_a(t_main *main)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		i;

	stack_a = init_new_stack(main);
	tmp = stack_a;
	i = 0;
	while (main->arr_char[i])
	{
		tmp->value = ft_atoi(main->arr_char[i]);
		if (main->arr_char[i + 1])
		{
			tmp->next = init_new_stack(main);
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		i++;
	}
	return (index_stack_a(&stack_a, make_arr_int(main), main));
}
