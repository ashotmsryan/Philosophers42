/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42lib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:17:03 by amsryan           #+#    #+#             */
/*   Updated: 2022/09/23 18:03:27 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str)
		if (!str[0])
			return (0);
	if (!str)
		return (0);
	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if ((str[i] < 48 || str[i] > 57))
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != '+')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	return (j);
}
