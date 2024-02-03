/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:52:57 by amsryan           #+#    #+#             */
/*   Updated: 2022/09/25 15:44:14 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*my_main(void *val)
{
	t_data	*info;

	info = (t_data *)val;
	info->last_ate_time = cur_time();
	if (info->thread_nmb % 2 == 0)
		usleep(20);
	while (1)
	{
		taking_forks(info);
		print_all(info, 2);
		_timer(info->time_to_eat);
		info->last_ate_time = cur_time();
		if (info->eat_count >= 0)
			info->eat_count++;
		putting_down_forks(info);
		print_all(info, 3);
		_timer(info->time_to_sleep);
		print_all(info, 4);
	}
}

int	making_threads(t_data *val, pthread_mutex_t *mutex)
{
	int	i;

	i = -1;
	pthread_mutex_init(val->pt, NULL);
	*val[0].start_time = cur_time();
	while (++i < val->nmb_philo)
	{
		val[i].start_time = val[0].start_time;
		pthread_mutex_init(&mutex[i], NULL);
		val[i].thread_nmb = i + 1;
	}
	i = -1;
	while (++i < val->nmb_philo)
	{
		if (thread_norm(i, val, mutex) != 0)
			return (1);
		if (pthread_detach(val[i].philos) != 0)
			return (1);
	}
	return (0);
}

int	norm_malloc(pthread_mutex_t **print, t_data **val,
	pthread_mutex_t **mutex, char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0
		|| (argv[5] && ft_atoi(argv[5]) <= 0) || odd_chars(argv) != 0)
	{
		printf("Wrong argument input!\n");
		return (1);
	}
	*print = malloc(sizeof (pthread_mutex_t));
	*val = malloc(ft_atoi(argv[1]) * sizeof (t_data));
	*mutex = malloc(ft_atoi(argv[1]) * sizeof (pthread_mutex_t));
	val[0]->start_time = malloc(sizeof(size_t));
	if (!print || !val || !mutex || !val[0]->start_time)
	{
		printf("Couldn't malloc() print/val/mutex!\n");
		return (1);
	}
	return (0);
}

int	norm_main(t_data *val, char **argv, pthread_mutex_t *print,
		pthread_mutex_t *mutex)
{
	int	i;
	int	n;

	i = -1;
	n = ft_atoi(argv[1]);
	val[0].dead = malloc(sizeof(int));
	*(val[0].dead) = 1;
	while (++i < n)
		val[i].dead = val[0].dead;
	i = 0;
	while (i < n)
	{
		if (parsing_time(argv, &val[i]))
			return (1);
		val[i].pt = print;
		i++;
	}
	if (making_threads(val, mutex) != 0)
		return (1);
	checking_6(val);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			*val;
	pthread_mutex_t	*print;
	pthread_mutex_t	*mutex;

	if (argc == 5 || argc == 6)
	{
		if (norm_malloc(&print, &val, &mutex, argv))
		{
			free_all(val, argv, mutex);
			return (1);
		}
		if (norm_main(val, argv, print, mutex) > 0)
		{
			free_all(val, argv, mutex);
			return (2);
		}
	}
	else
	{
		printf("Less/more argument input!\n");
		return (3);
	}
	free_all(val, argv, mutex);
	return (0);
}
