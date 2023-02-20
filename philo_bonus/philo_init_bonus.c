/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:39:03 by babkar            #+#    #+#             */
/*   Updated: 2023/02/20 14:43:50 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_shared	*ft_create_semaphores(t_shared *data)
{
	sem_unlink("fork");
	sem_unlink("protect");
	sem_unlink("print");
	data->semaphore = sem_open("fork", O_CREAT, 0, data->nbr);
	data->protect = sem_open("protect", O_CREAT, 0, 1);
	data->print = sem_open("print", O_CREAT, 0, 1);
	return (data);
}

void print_address(t_philo *pidsm, int size)
{
	puts("pids");
	while(size--)
	{
		printf("%p\n", pidsm);
		pidsm++;
	}
}
void	init_data(t_shared *data, char **av)
{
	pthread_mutex_t	*fork;

	data->nbr = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->time_must_eat = -1;
	if (av[5])
		data->time_must_eat = ft_atoi(av[5]);
	data->time_birth = get_time();
	data->death = 0;
	data = ft_create_semaphores(data);
	data->pid = (int *)malloc(data->nbr * sizeof(pid_t));
	if (!data->pid)
		exit(1);
	data->full = 0;
}

t_philo	*philo_init(t_philo *p, t_shared *data, int ac)
{
	int	i;
	int	size;

	i = 0;
	size = data->nbr + 1;
	if (ac == 6)
		size++;
	p = (t_philo *)malloc(size * sizeof(t_philo));
	print_address(p, size); 
	if (!p)
		exit(1);
	while (i < size)
	{
		p[i].data = data;
		p[i].index = i;
		p[i].last_meal = get_time();
		p[i].check_time_must_eat = 0;
		p[i].t = NULL;
		i++;
	}
	return (p);
}
