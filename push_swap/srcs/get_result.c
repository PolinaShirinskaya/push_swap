/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:33:55 by adian             #+#    #+#             */
/*   Updated: 2022/03/28 23:33:56 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*make_str(char *s1, char *s2)
{
	char	*str1;
	char	*str2;

	if (s1)
	{
		str1 = ft_strjoin(s1, "\n");
		free (s1);
		if (!str1)
			return (NULL);
	}
	else
		str1 = s1;
	str2 = ft_strjoin(str1, s2);
	free (str1);
	if (!str2)
		return (NULL);
	return (str2);
}

char	*get_result(t_main *main)
{
	char		*str;
	t_command	*tmp;

	tmp = main->res;
	str = NULL;
	while (tmp->command)
	{
		str = make_str(str, tmp->command);
		if (!str)
			exit(error("Error: malloc out res\n", main));
		tmp = tmp->next;
	}
	return (str);
}
