/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:36:42 by juhlee            #+#    #+#             */
/*   Updated: 2021/03/23 21:09:48 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	kill_process(void)
{
	int	i;

	i = 0;
	while (i < g_table.num_of_philo)
	{
		kill(g_philos[i].pid, SIGKILL);
		i++;
	}
}

void	process_monitor(void)
{
	int	i;
	int	status;
	int	eat;

	eat = 0;
	while (1)
	{
		i = 0;
		while (i < g_table.num_of_philo)
		{
			status = -1;
			waitpid(g_philos[i].pid, &status, WNOHANG);
			if (status == 256)
				break ;
			if (status == 0 && ++eat)
				if (eat == g_table.num_of_philo)
					break ;
			++i;
		}
		if (i != g_table.num_of_philo)
		{
			kill_process();
			break ;
		}
	}
}
