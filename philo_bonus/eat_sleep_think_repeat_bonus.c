/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think_repeat_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:40:14 by babkar            #+#    #+#             */
/*   Updated: 2022/06/29 17:23:16 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*eat(t_philo *p, t_shared *data)
{
	sem_wait(data->semaphore);
	ft_print("has taken a fork", p, data);
	sem_wait(data->semaphore);
	ft_print("has taken a fork", p, data);
	ft_print("is eating", p, data);
	p->last_meal = get_time();
	p->check_time_must_eat += 1;
	ft_usleep(data->time_eat);
	sem_post(data->semaphore);
	sem_post(data->semaphore);
	if (p->check_time_must_eat == data->time_must_eat)
		exit(0);
	return (ft_sleep(p, data));
}

void	*ft_sleep(t_philo *p, t_shared *data)
{
	ft_print("is sleeping", p, data);
	ft_usleep(p->data->time_sleep);
	return (think(p, data));
}

void	*think(t_philo *p, t_shared *data)
{
	ft_print("is thinking", p, data);
	return (eat(p, data));
}

void	*check_death(void *arg)
{
	t_philo		*p;
	t_shared	*data;
	int			i;
	int			count;

	count = 0;
	i = 0;
	p = (t_philo *)arg;
	data = p->data;
	while (1)
	{
		if (get_time() - p->last_meal > data->time_die)
		{
			data->death = 1;
			sem_wait(data->protect);
			sem_wait(data->print);
			printf("[%05llu] %d died\n",
				get_time() - data->time_birth, i + 1);
			break ;
		}
	}
	exit(0);
	return (NULL);
}
