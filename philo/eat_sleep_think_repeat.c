/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think_repeat.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:40:14 by babkar            #+#    #+#             */
/*   Updated: 2022/07/06 11:38:20 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_index(t_philo *p, t_shared *data, int i)
{
	if (i == 0)
		return (p->index - 1);
	return ((p->index) % data->nbr);
}

void	*eat(t_philo *p, t_shared *data)
{
	pthread_mutex_lock(&data->fork[fork_index(p, data, 0)]);
	if (ft_print("has taken a fork", p, data))
		return (NULL);
	pthread_mutex_lock(&data->fork[fork_index(p, data, 1)]);
	if (ft_print("has taken a fork", p, data))
		return (NULL);
	if (ft_print("is eating", p, data))
		return (NULL);
	p->last_meal = get_time();
	if (p->check_time_must_eat < data->time_must_eat
		&& p->check_time_must_eat != -1)
		p->check_time_must_eat += 1;
	ft_usleep(data->time_eat);
	pthread_mutex_unlock(&data->fork[fork_index(p, data, 0)]);
	pthread_mutex_unlock(&data->fork[fork_index(p, data, 1)]);
	return (ft_sleep(p, data));
}

void	*ft_sleep(t_philo *p, t_shared *data)
{
	if (ft_print("is sleeping", p, data))
		return (NULL);
	ft_usleep(p->data->time_sleep);
	return (think(p, data));
}

void	*think(t_philo *p, t_shared *data)
{
	if (ft_print("is thinking", p, data))
		return (NULL);
	return (eat(p, data));
}

void	*check_death(void *arg)
{
	t_philo		*p;
	int			i;
	int			count;

	count = 0;
	i = 0;
	p = (t_philo *)arg;
	while (get_time() - p[i].last_meal <= p->data->time_die)
	{
		count += p[i].check_time_must_eat;
		if (count == p->data->nbr * p->data->time_must_eat)
		{
			p->data->full = 1;
			return (NULL);
		}
		i++;
		if (p->data->nbr == i)
		{
			i = 0;
			count = 0;
		}
	}
	p->data->death = 1;
	printf("[%05llu] %d died\n", get_time() - p->data->time_birth, i + 1);
	return (NULL);
}
