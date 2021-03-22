/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:08:19 by ijuhae            #+#    #+#             */
/*   Updated: 2021/03/22 15:57:09 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		check_arg(int argc, char **argv)
{
	if ((g_table.num_of_philos = ft_atoi(argv[1])) <= 1 ||
		(g_table.time_to_die = ft_atoi(argv[2])) <= 0 ||
		(g_table.time_to_eat = ft_atoi(argv[3])) <= 0 ||
		(g_table.time_to_sleep = ft_atoi(argv[4])) <= 0)
		return (1);
	if (argc == 6 && (g_table.must_num_of_eat = ft_atoi(argv[5])) <= 0)
		return (1);
	else if (argc == 5)
		g_table.must_num_of_eat = -1;
	return (0);
}

void	init_table(void)
{
	int	i;

	i = 0;
	while (i < g_table.num_of_philos)
	{
		pthread_mutex_init(&g_table.fork[i], NULL);
		g_philos[i].idx = i;
		g_philos[i].l_fork = i;
		g_philos[i].r_fork = (i + 1) % g_table.num_of_philos;
		g_philos[i].num_of_eat = 0;
		++i;
	}
	pthread_mutex_init(&g_table.m_msg, NULL);
	g_table.base_time = get_time();
	g_table.eat = 0;
	g_table.dead = 0;
}

void init_philos(void)
{
	int	i;

	i = 0;
	while (i < g_table.num_of_philos)
	{
		g_philos[i].last_eat = get_time();
		pthread_create(&g_philos[i].tid, NULL, philo_act, &g_philos[i]);
		++i;
	}
	i = 0;
	while (i < g_table.num_of_philos)
	{
		pthread_join(g_philos[i].tid, NULL);
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6) || check_arg(argc, argv))
		return (printf("Error: arguments"));
	if (!(g_philos = (t_philo *)malloc(sizeof(t_philo) * g_table.num_of_philos)))
		return (printf("Error: malloc philos"));
	if (!(g_table.fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * g_table.num_of_philos)))
		return (printf("Error: malloc forks"));
	init_table();
	init_philos();
	return (0);
}
