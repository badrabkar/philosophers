/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:02:00 by babkar            #+#    #+#             */
/*   Updated: 2022/07/04 12:06:50 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*p;
	t_shared	*data;

	p = (t_philo *)arg;
	data = p->data;
	return (eat(p, data));
	return (NULL);
}

void	ft_free(t_philo *p, t_shared *data)
{
	int	i;

	i = 0;
	while (i < data->nbr)
		pthread_mutex_destroy(&data->fork[i++]);
	i = 0;
	while (i < data->size)
		pthread_detach(p[i++].t);
	free(data->fork);
}

int	ft_pthread_create(t_philo *p)
{
	int			i;
	t_shared	*data;

	data = p->data;
	i = 0;
	while (i < data->nbr)
	{
		pthread_create(&p[i].t, NULL, &routine, &p[i]);
		usleep(1000);
		i++;
	}
	check_death(p);
	return (0);
}

int	ft_pthread_join(t_philo *p)
{
	int			i;
	t_shared	*data;

	data = p->data;
	i = 0;
	while (i < data->size)
		pthread_join(p[i++].t, NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		*p;
	t_shared	data;
	int			i;

	p = NULL;
	i = 0;
	if (parsing(ac, av))
		return (1);
	if (init_data(&data, av))
		return (1);
	p = philo_init(p, &data, ac);
	if (!p)
		return (1);
	if (ft_pthread_create(p))
		return (1);
	ft_free(p, &data);
	free(p);
	return (0);
}
