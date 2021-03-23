/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:08:53 by ijuhae            #+#    #+#             */
/*   Updated: 2021/03/23 21:06:26 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

# define TAKEN_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DEAD		4

typedef struct		s_table
{
	int				num_of_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				must_num_of_eat;

	unsigned long	base_time;
	int				eat;
	int				dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_msg;
}					t_table;

typedef struct		s_philo
{
	int				idx;
	int				l_fork;
	int				r_fork;
	int				num_of_eat;
	unsigned long	last_eat;
	pthread_t		tid;
}					t_philo;

t_table				g_table;
t_philo				*g_philos;

int					ft_atoi(const char *str);
unsigned long		get_time(void);
void				less_err_sleep(unsigned long input);
void				*philo_act(void *phi);

#endif
