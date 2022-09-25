/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:54:09 by amsryan           #+#    #+#             */
/*   Updated: 2022/09/25 14:34:12 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_struct
{
	int				nmb_philo;
	int				thread_nmb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				cycle_of_eat;
	int				*dead;
	int				eat_count;
	size_t			time;
	size_t			*start_time;
	size_t			last_ate_time;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*pt;
	pthread_t		philos;
}				t_data;
int		ft_atoi(const char *str);
int		parsing_time(char **av, t_data *tmp);
int		odd_chars(char **argv);
int		thread_norm(int i, t_data *val, pthread_mutex_t *mutex);
size_t	ft_strlen(char *str);
size_t	cur_time(void);
long	my_time(t_data *info);
void	*my_main(void *val);
void	_timer(size_t tt);
void	taking_forks(t_data *info);
void	putting_down_forks(t_data *info);
void	print_all(t_data *info, int flag);
void	making_forks(t_data *val, pthread_mutex_t *mutex);
void	checking_6(t_data *val);
void	increasing_eat_count(t_data *info);
void	check_death(t_data *info);
void	free_all(t_data *val, char **av, pthread_mutex_t *mutex);

#endif
