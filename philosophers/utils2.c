/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:05:04 by amsryan           #+#    #+#             */
/*   Updated: 2022/09/25 15:14:36 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_timer(size_t tt)
{
	size_t	time;
	size_t	n_time;

	time = cur_time();
	// n_time = cur_time();
	n_time = time;
	while ((n_time - time) < tt)
	{
		n_time = cur_time();
		usleep(10);
	}
}

int	thread_norm(int i, t_data *val, pthread_mutex_t *mutex)
{
	making_forks(&val[i], mutex);
	if (pthread_create(&val[i].philos, NULL, &my_main, &(val[i])) != 0)
	{
		printf("Couldn't start creating thread!\n");
		return (1);
	}
	return (0);
}

size_t	cur_time(void)
{
	struct timeval	t;
	size_t			time;	

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (time);
}

void	free_all(t_data *val, char **av, pthread_mutex_t *mutex)
{
	int	i;
	int	s;

	i = -1;
	s = ft_atoi(av[1]);
	if (val && val[0].pt)
		free(val[0].pt);
	if (val && val[0].start_time)
		free(val[0].start_time);
	if (val && val[0].dead)
		free(val[0].dead);
	while (mutex && s >= 0 && ++i < s)
		pthread_mutex_destroy(&mutex[i]);
	if (mutex)
		free(mutex);
	if (val)
		free(val);
}
