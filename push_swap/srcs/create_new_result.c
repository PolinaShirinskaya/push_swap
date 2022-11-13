/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:33:42 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:33:43 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_command	*create_new_result(t_main *main)
{
	t_command	*new;

	new = (t_command *)malloc(sizeof(t_command));
	if (!new)
		exit (error("Error: malloc 'res'\n", main));
	new->command = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
