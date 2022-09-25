/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:44:45 by amsryan           #+#    #+#             */
/*   Updated: 2022/09/25 14:34:15 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	putting_down_forks(t_data *info)
{
	pthread_mutex_unlock(info->right_fork);
	pthread_mutex_unlock(info->left_fork);
}

int	odd_chars(char **a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == '+' && (a[i][j + 1] >= '0' && a[i][j + 1] <= '9')
					&& (a[i][j - 1] >= '0' && a[i][j - 1] <= '9'))
				return (1);
			if ((a[i][j] >= 48 && a[i][j] <= 57) || (a[i][j] == '+'
				&& a[i][j + 1] != '+'))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}	

void	making_forks(t_data *val, pthread_mutex_t *mutex)
{
	if (val->thread_nmb == val->nmb_philo)
		val->left_fork = &mutex[0];
	else
		val->left_fork = &mutex[val->thread_nmb];
	val->right_fork = &mutex[val->thread_nmb - 1];
}

int	parsing_time(char **av, t_data *tmp)
{
	if (!tmp)
	{
		printf("Couldn't malloc() structure!\n");
		return (1);
	}
	tmp->nmb_philo = ft_atoi(av[1]);
	tmp->time_to_die = ft_atoi(av[2]);
	tmp->time_to_eat = ft_atoi(av[3]);
	tmp->time_to_sleep = ft_atoi(av[4]);
	if (av[5] && ft_atoi(av[5]) > 0)
		tmp->cycle_of_eat = ft_atoi(av[5]);
	else
		tmp->cycle_of_eat = -1;
	return (0);
}

void	print_all(t_data *info, int flag)
{
	pthread_mutex_lock(info->pt);
	my_time(info);
	if (*info->dead == 1)
	{
		if (flag == 0)
			printf("%ld %d has taken a fork\n", info->time, info->thread_nmb);
		else if (flag == 1)
			printf("%ld %d has taken a fork\n", info->time, info->thread_nmb);
		else if (flag == 2)
			printf("%ld %d is eating\n", info->time, info->thread_nmb);
		else if (flag == 3)
			printf("%ld %d is sleeping\n", info->time, info->thread_nmb);
		else if (flag == 4)
			printf("%ld %d is thinking\n", info->time, info->thread_nmb);
		else if (flag == 6)
			printf("%ld ALL ATE %d TIMES\n", info->time, info->cycle_of_eat);
	}
	else if (*info->dead == 0 && flag == 5)
		printf("%ld %d died\n", info->time, info->thread_nmb);
	pthread_mutex_unlock(info->pt);
}
