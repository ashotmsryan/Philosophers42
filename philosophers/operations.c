/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:34:02 by amsryan           #+#    #+#             */
/*   Updated: 2022/09/25 15:15:00 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_data *info)
{
	pthread_mutex_lock(info->left_fork);
	if (*info->dead == 1)
		print_all(info, 1);
	pthread_mutex_lock(info->right_fork);
	if (*info->dead == 1)
		print_all(info, 0);
}

int	checking_if_finished(t_data *val)
{
	int	i;

	i = 0;
	while (i < val[0].nmb_philo && val[i].eat_count >= val->cycle_of_eat
		&& val->cycle_of_eat != -1)
		i++;
	if (i == val[0].nmb_philo)
	{
		return (1);
	}
	return (0);
}

void	check_death(t_data *info)
{
	size_t	t_now;

	t_now = cur_time();
	t_now = t_now - info->last_ate_time;
	if (t_now >= (size_t)info->time_to_die)
		*info->dead = 0;
}

void	checking_6(t_data *val)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == val->nmb_philo)
			i = 0;
		usleep(10);
		check_death(&val[i]);
		if ((checking_if_finished(val) == 1) || *val->dead == 0)
		{
			i = 0;
			if (*val->dead == 1)
			{
				print_all(val, 6);
				*val->dead = 0;
			}
			else if (*val->dead == 0)
				print_all(val, 5);
			return ;
		}
		i++;
	}
}

long	my_time(t_data *info)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	t.tv_sec *= 1000;
	t.tv_usec /= 1000;
	info->time = (t.tv_sec + t.tv_usec)
		- *info->start_time;
	return (info->time);
}
