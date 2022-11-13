/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_input_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:34:22 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:34:23 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	str_is_digit(char const *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static long long int	ft_atoi_ll(char const *str)
{
	long long int	num;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

static int	check_int(int len_arr, char **arr)
{
	int	i;

	i = 0;
	while (i < len_arr)
	{
		if (ft_atoi_ll(arr[i]) < -2147483648 || \
		ft_atoi_ll(arr[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	validation_input_data(int len_arr, char **arr)
{
	int	i;
	int	j;

	if (len_arr < 1)
		return (0);
	i = 0;
	while (arr[i])
	{
		if (!str_is_digit(arr[i++]))
			return (-1);
	}
	i = 0;
	while (i < len_arr - 1)
	{
		j = i + 1;
		while (j < len_arr)
		{
			if (!ft_strcmp(arr[i], arr[j++]))
				return (-1);
		}
		i++;
	}
	if (!check_int(len_arr, arr))
		return (-1);
	return (1);
}
