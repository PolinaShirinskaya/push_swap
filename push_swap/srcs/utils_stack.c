/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:34:15 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:34:16 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	len_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_min_value(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = 0;
	if (tmp)
	{
		min = tmp->index;
		while (tmp)
		{
			if (tmp->index < min)
				min = tmp->index;
			tmp = tmp->next;
		}
	}
	return (min);
}

int	find_max_value(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = 0;
	if (tmp)
	{
		max = tmp->index;
		while (tmp)
		{
			if (tmp->index > max)
				max = tmp->index;
			tmp = tmp->next;
		}
	}
	return (max);
}

int	find_index(t_stack **stack, int index)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 1;
	while (tmp->index != index)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*end_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
