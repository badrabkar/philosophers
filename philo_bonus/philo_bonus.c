/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:04:19 by babkar            #+#    #+#             */
/*   Updated: 2022/07/04 12:04:57 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(void *arg)
{
	t_philo		*p;
	t_shared	*data;

	p = (t_philo *)arg;
	data = p->data;
	eat(p, data);
}

void	kill_child_processes(t_shared *data)
{
	int	i;

	i = 0;
	while (i < data->nbr)
		kill(data->pid[i++], SIGKILL);
}

void	ft_create_processes(t_philo *p, t_shared *data)
{
	int	i;

	i = 0;
	while (i < data->nbr)
	{
		data->pid[i] = fork();
		if (data->pid[i] == 0)
		{
			pthread_create(&p[i].t, NULL, &check_death, &p[i]);
			routine(&p[i]);
			exit(0);
		}
		i++;
	}
}

void	ft_free(t_philo *p, t_shared *data)
{
	sem_unlink("fork");
	sem_unlink("protect");
	sem_unlink("print");
	sem_close(data->semaphore);
	sem_close(data->print);
	sem_close(data->protect);
	free(data->pid);
}

int	main(int ac, char **av)
{
	t_philo		*p;
	t_shared	data;
	int			i;

	p = NULL;
	parsing(ac, av);
	init_data(&data, av);
	p = philo_init(p, &data, ac);
	ft_create_processes(p, &data);
	waitpid(-1, 0, 0);
	kill_child_processes(&data);
	ft_free(p, &data);
	free(p);
	return (0);
}
