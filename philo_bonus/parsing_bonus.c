/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:38:48 by babkar            #+#    #+#             */
/*   Updated: 2022/06/29 16:58:01 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_arguments(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == 0)
			exit(1);
		i++;
	}
}

void	parsing(int ac, char **av)
{
	if (ac != 6 && ac != 5)
		exit(1);
	check_arguments(ac, av);
}
