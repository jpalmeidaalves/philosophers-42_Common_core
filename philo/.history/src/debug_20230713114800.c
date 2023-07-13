/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:12:08 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/13 11:48:00 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    print_philos(t_data info, t_philo philo)
{
    (void)philo;
    printf("nb_of_philos: %d\n", info.nb_of_philos);
    printf("time to die: %ld\n", info.time_do_die);
    printf("time to eat: %ld\n", info.time_to_eat);
    printf("time_to_sleep: %ld\n", info.time_to_sleep);
    if (info.nb_rounds > 0)
        printf("nb_of_times: %d\n", info.nb_rounds);
    printf("philo start time:%ld\n", info.start_time);
    /* int i = 0;
    while (i < info.nb_of_philos)
    {
        printf("\tphilo ID: %d \n", philo.id);
        // printf("\t  right fork: %d \n", info.philo[i].right_fork);
        // printf("\t  left fork: %d \n", info.philo[i].left_fork);
        printf("\t  last meal: %ld\n", philo.last_meal);
        i++;
    } */
}