/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:34:02 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:34:03 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**dup_arr(char	**arr, int len)
{
	char	**out;
	int		i;

	out = (char **)malloc(sizeof(char *) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = ft_strdup(arr[i + 1]);
		if (!out[i])
		{
			free_arr_char(out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}

char	**parsing_input_data(int argc, char **argv, t_main *main)
{
	char	**arr;

	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = dup_arr(argv, argc - 1);
	if (!arr)
		exit(error("Error: malloc 'parsing input data'\n", main));
	return (arr);
}
