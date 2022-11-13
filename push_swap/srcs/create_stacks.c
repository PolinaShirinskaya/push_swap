/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:33:48 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:33:49 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_main	*create_stacks(void)
{
	t_main	*main;

	main = (t_main *)malloc(sizeof(t_main));
	if (!main)
		exit(error("Error: malloc 'main'\n", NULL));
	main->a = NULL;
	main->b = NULL;
	main->numbers = 0;
	main->arr_char = NULL;
	return (main);
}
