/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:33:24 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:33:25 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	write_command(t_main *main, char const *str, int done)
{
	t_command	*tmp;

	tmp = main->res;
	while (tmp->command)
		tmp = tmp->next;
	if (done == 1)
	{
		tmp->command = ft_strdup(str);
		if (!tmp->command)
			exit(error("Error: malloc 'command'\n", main));
		tmp->next = create_new_result(main);
		tmp->next->prev = tmp;
	}
}

void	command(t_main *main, char const *str)
{
	if (!ft_strcmp(str, "sa"))
		write_command(main, str, sa_sb(&(main->a)));
	else if (!ft_strcmp(str, "sb"))
		write_command(main, str, sa_sb(&(main->b)));
	else if (!ft_strcmp(str, "ss"))
		write_command(main, str, ss(&(main->a), &(main->b)));
	else if (!ft_strcmp(str, "pa"))
		write_command(main, str, pa_pb(&(main->b), &(main->a)));
	else if (!ft_strcmp(str, "pb"))
		write_command(main, str, pa_pb(&(main->a), &(main->b)));
	else if (!ft_strcmp(str, "ra"))
		write_command(main, str, ra_rb(&(main->a)));
	else if (!ft_strcmp(str, "rb"))
		write_command(main, str, ra_rb(&(main->b)));
	else if (!ft_strcmp(str, "rr"))
		write_command(main, str, rr(&(main->a), &(main->b)));
	else if (!ft_strcmp(str, "rra"))
		write_command(main, str, rra_rrb(&(main->a)));
	else if (!ft_strcmp(str, "rrb"))
		write_command(main, str, rra_rrb(&(main->b)));
	else if (!ft_strcmp(str, "rrr"))
		write_command(main, str, rrr(&(main->a), &(main->b)));
}
