/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:32:43 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:32:44 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	return (sa_sb(stack_a) || sa_sb(stack_b));
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	return (ra_rb(stack_a) && ra_rb(stack_b));
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	return (rra_rrb(stack_a) && rra_rrb(stack_b));
}
