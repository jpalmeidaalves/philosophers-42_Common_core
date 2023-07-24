/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:58:00 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/21 22:08:36 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int      is_ph_dead(t_philo *ph)
{
    int     i;
    t_data  *info;

    info = ph->info;
    i = -1;
    while (++i < info->nb_of_philos)
    {
        pthread_mutex_lock(&info->check_end);
		if (check_death(&ph[i]))
		{
			printf("%ld %d, is dead",get_time() - info->start_time, ph[i].id);
			info->end_of_simulation = 1;
			pthread_mutex_unlock(&info->check_end);
			return (1);
		}
		pthread_mutex_unlock(&info->check_end);
		i++;
	}
	return (0);
}
static int      all_ph_ate(t_philo *ph)
{
	int	i;
    t_data  *info;

	i = 0;
    info = ph->info;
	while (i < info->nb_of_philos)
	{
		if (ph[i].nb_meals < info->total_rounds)
			return (0);
		i++;
	}
	return (1);
}

void    *monitor(void *arg)
{
    t_philo     *ph;
    t_data      *info;

    ph = (t_philo *)arg;
    info = ph->info;
    while (1)
    {
        if (is_ph_dead(ph))
            return (NULL);
        pthread_mutex_lock(&info->check_end);
        if (info->total_rounds != -1 && all_ph_ate(ph))
        {
            info->end_of_simulation = 1;
            pthread_mutex_unlock(&info->check_end);
            return (NULL);
        }
        pthread_mutex_unlock(&info->check_end);
    }
}