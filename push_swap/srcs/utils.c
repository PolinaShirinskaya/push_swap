/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:34:18 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:34:19 by adian            ###   ########.fr       */
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
	main->res = create_new_result(main);
	main->arr_char = NULL;
	return (main);
}

int	check_sort_input_data(char **arr)
{
	int	i;
	int	len;

	i = 0;
	len = len_arr_str(arr);
	while (i < len - 1)
	{
		if (ft_atoi(arr[i]) > ft_atoi(arr[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	len_arr_str(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	error(char *str, t_main *main)
{
	ft_putstr_fd(str, 2);
	free_main(main);
	return (1);
}

void	print_result(char *res)
{
	ft_putstr_fd(res, 1);
	ft_putchar_fd('\n', 1);
	free (res);
	res = NULL;
}
