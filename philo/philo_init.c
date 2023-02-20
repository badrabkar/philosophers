/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:36:41 by babkar            #+#    #+#             */
/*   Updated: 2023/02/20 14:38:18 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_shared *data, char **av)
{
	pthread_mutex_t	*fork;
	int				i;

	data->nbr = ft_atoi(av[1]);
	data->size = data->nbr + 1;
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->time_must_eat = -1;
	if (av[5])
	{
		data->time_must_eat = ft_atoi(av[5]);
		data->size++;
	}
	data->time_birth = get_time();
	data->death = 0;
	fork = malloc(data->nbr * sizeof(pthread_mutex_t));
	printf("%p\n", fork);
	if (!fork)
		return (1);
	i = 0;
	while (i < data->nbr)
		pthread_mutex_init(&fork[i++], NULL);
	data->fork = fork;
	data->full = 0;
	return (0);
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
	if (!p)
		return (NULL);
	while (i < size)
	{
		p[i].data = data;
		p[i].index = i + 1;
		p[i].last_meal = get_time();
		p[i].check_time_must_eat = 0;
		p[i].t = NULL;
		i++;
	}
	return (p);
}
