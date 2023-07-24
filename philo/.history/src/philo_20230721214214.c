/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:18:50 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/21 21:42:14 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* void    *debug_function(void *arg)
{
    t_data  *info;

    int i = 0;    
    info = (t_data *)arg;
    while (i < 1000000)
    {
        pthread_mutex_lock(&info->philo_muts[0]);
        info->var++;
        pthread_mutex_unlock(&info->philo_muts[0]);
        i++;
    }
    return (NULL);
}*/




int    start_philo(int ac, char **args)
{
    t_data      *info;
    t_philo     *philo;

    start_info(&info,ac, args);
    init_philo(&info, philo);
    if (info->nb\
    )
    start_philos_threads(&info, &philo);
    // print_philos(info, *philo);
    free_struct(&info);
    return (0);
}

int     main(int ac, char**av)
{
    if (check_input(ac, av) < 0)
        return (-1);
    start_philo(ac, av);    
    return (0);
}

