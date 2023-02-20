/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 07:37:23 by babkar            #+#    #+#             */
/*   Updated: 2022/06/29 10:26:00 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arguments(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == -1 || ft_atoi(av[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	parsing(int ac, char **av)
{
	if (ac != 6 && ac != 5)
		return (1);
	if (check_arguments(ac, av))
		return (1);
	return (0);
}
