/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:36:42 by juhlee            #+#    #+#             */
/*   Updated: 2021/03/23 20:49:29 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

// int kill_process(void)
void	kill_process(void)
{
	int	i;

	i = 0;
	while (i < g_table.num_of_philos)
	{
		kill(g_philos[i].pid, SIGKILL);
		i++;
	}
	// return (1);
}

void process_monitor(void)
{
	int	i;
	int	status;
	int	eat;

	eat = 0;
	while (1)
	{
		i = 0;
		while (i < g_table.num_of_philos)
		{
			status = -1;
			waitpid(g_philos[i].pid, &status, WNOHANG);
			if (status == 256)
				break ;
			if (status == 0 && ++eat)
				if (eat == g_table.num_of_philos)
					break ;
			++i;
		}
		if (i != g_table.num_of_philos)
		{
			kill_process();
			break ;
		}
	}
}
