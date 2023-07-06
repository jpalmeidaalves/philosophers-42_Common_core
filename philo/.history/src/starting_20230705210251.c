/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:04:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/05 21:02:52 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    init_philos_thread(t_data *info)
{
    int i;

    i = 0;
    info->philo.threads_ph = malloc(sizeof(pthread_t) * info->nb_of_philos);
    while (i < info->nb_of_philos)
    {
        pthread_create(&info->philo.threads_ph[i], NULL, function, (void *)info);
        i++;
    }
    i = 0;
    while (i < info->nb_of_philos)
    {
        pthread_join(info->philo.threads_ph[i], NULL);
        i++;
    }
}