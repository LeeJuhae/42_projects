/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:33:32 by ijuhae            #+#    #+#             */
/*   Updated: 2021/03/22 16:47:33 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
		g_philos[i].idx = i;
		g_philos[i].num_of_eat = 0;
		++i;
	}
	g_table.base_time = get_time();
	g_table.eat = 0;
	g_table.dead = 0;
	g_table.enter = sem_open("/enter", O_CREAT | O_EXCL, 0777,
					g_table.num_of_philos / 2);
	g_table.m_msg = sem_open("/m_msg", O_CREAT | O_EXCL, 0777, 1);
	sem_unlink("/enter");
	sem_unlink("m_msg");
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

void	clean_table(void)
{
	sem_close(g_table.enter);
	sem_close(g_table.m_msg);
	free(g_philos);
}

int		main(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6) || check_arg(argc, argv))
		return (printf("Error: arguments"));
	if (!(g_philos = (t_philo *)malloc(sizeof(t_philo) * g_table.num_of_philos)))
		return (printf("Error: malloc philos"));
	init_table();
	init_philos();
	clean_table();
	return (0);
}
