/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:34:12 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:35:32 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sec_radix(t_main *main, int max_bits, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((main->a->index >> i) & 1) == 1)
				command(main, "ra");
			else
				command(main, "pb");
			j++;
		}
		while (main->b)
			command(main, "pa");
		i++;
	}
}

void	radix(t_main *main)
{
	int	len;
	int	max;
	int	bits;

	len = len_stack(&(main->a));
	max = len - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	sec_radix(main, bits, len);
}
