/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:01:53 by babkar            #+#    #+#             */
/*   Updated: 2022/06/29 12:14:17 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_shared
{
	int				nbr;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_must_eat;
	long long		time_birth;
	int				death;
	int				full;
	int				size;
	pthread_mutex_t	*fork;
}	t_shared;

typedef struct s_philo
{
	int				index;
	long long		last_meal;
	int				check_time_must_eat;
	pthread_t		t;
	t_shared		*data;
}	t_philo;

long long	get_time(void);
int			ft_atoi(const char *str);
void		ft_usleep(int time);
int			ft_isdigit(int c);
int			ft_print(char *str, t_philo *p, t_shared *data);
int			parsing(int ac, char **av);
t_philo		*philo_init(t_philo *p, t_shared *data, int ac);
int			init_data(t_shared *data, char **av);
void		philo_info(t_philo *p, t_shared *data, int i);
void		*eat(t_philo *p, t_shared *data);
void		*think(t_philo *p, t_shared *data);
void		*ft_sleep(t_philo *p, t_shared *data);
void		*check_time_must_eat(void	*arg);
void		*check_death(void *arg);
#endif
