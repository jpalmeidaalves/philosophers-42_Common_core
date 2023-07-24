/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:18:50 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/24 15:04:47 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	cleaning(t_data *info, t_philo *ph)
{
	int		i;

	i = -1;
	while (++i < info->nb_of_philos)
		pthread_mutex_destroy(&ph[i].left_fork);
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->check_end);
	if (ph)
		free(ph);
	return (0);
}

void	one_philo_simulation(t_data *info)
{
	printf("0 1 has taken a fork\n");
	info->start_time = get_time();
	milisleep(info->time_do_die);
	printf("%ld 1 died\n", get_time() - info->start_time);
}

int	main(int ac, char **av)
{
	t_data		info;
	t_philo		*philo;
	
	if (check_input(ac, av) < 0)
		return (-1);
	start_info(&info, ac, av);
	philo = malloc(sizeof(t_philo) * info.nb_of_philos);
	init_philo(&info, philo);
	if (info.nb_of_philos == 1)
		one_philo_simulation(&info);
	else
	{
		if (start_philos_threads(&info, philo) == 0)
		{
			printf("Error creating threads\n");
			return (-1);
		}
	}
	cleaning(&info, philo);
	return (0);
}
