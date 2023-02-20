/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:04:22 by babkar            #+#    #+#             */
/*   Updated: 2022/07/02 11:17:59 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>           /* For O_* constants */
# include <sys/stat.h> /* For mode constants */
# include <signal.h>

typedef struct s_shared
{
	int				nbr;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_must_eat;
	long long		time_birth;
	int				full;
	int				death;
	sem_t			*semaphore;
	sem_t			*protect;
	sem_t			*print;
	pid_t			*pid;
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
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *str);
void		ft_usleep(int time);
int			ft_isdigit(int c);
void		ft_print(char *str, t_philo *p, t_shared *data);
void		parsing(int ac, char **av);
t_philo		*philo_init(t_philo *p, t_shared *data, int ac);
void		init_data(t_shared *data, char **av);
void		philo_info(t_philo *p, t_shared *data, int i);
void		*eat(t_philo *p, t_shared *data);
void		*think(t_philo *p, t_shared *data);
void		*ft_sleep(t_philo *p, t_shared *data);
void		*check_time_must_eat(void	*arg);
void		*check_death(void *arg);
void		*trap(void *arg);
void		*check_full(void *arg);
void		kill_child_processes(t_shared *data);
#endif
