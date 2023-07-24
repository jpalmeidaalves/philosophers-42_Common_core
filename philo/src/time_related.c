/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_related.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:58:59 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/22 21:40:14 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	milisleep(unsigned int nb)
{
	usleep(nb * 1000);
}

uint64_t	get_time(void)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	return ((t1.tv_sec * (uint64_t)1000) + t1.tv_usec / 1000);
}
/* Retunrs the elapsed time since the start of the simulation in ms*/

uint64_t	elapsed_time(t_data *info)
{
	return (get_time() - info->start_time);
}

/* Retunrs 1 if the time since last_meal is greater than time_to_die*/

int	check_death(t_philo *ph)
{
	return ((get_time() - ph->last_meal) >= ph->info->time_do_die);
}
