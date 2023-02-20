/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:39:11 by babkar            #+#    #+#             */
/*   Updated: 2022/06/29 16:58:49 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '+')
		exit(1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit(1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

long long	get_time(void)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(int time)
{
	long long	current_time;

	current_time = get_time();
	while (get_time() - current_time < time)
		usleep(500);
}

void	ft_print(char *str, t_philo *p, t_shared *data)
{
	sem_wait(data->print);
	if (data->death == 1)
	{
		printf("[%05llu] %d died\n",
			get_time() - data->time_birth, p->index + 1);
		exit(0);
	}
	printf("[%05llu] %d %s\n",
		get_time() - p->data->time_birth, p->index + 1, str);
	sem_post(data->print);
}
