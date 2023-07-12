/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:08:20 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/11 11:24:44 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    free_struct(t_data *info)
{
    free(info->philo_muts);
    free(info->forks);
}

void    join_thread(t_philo *philo, t_data info)
{
    int i;

    i = 0;
    printf("nbfil2 %d\n", info.nb_of_philos);
    while (i < info.nb_of_philos)
    {
        pthread_join(philo[i].threads_ph, NULL);
        i++;
    }
}