/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:12:08 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/04 10:12:09 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    print_philos(t_data philos)
{
    printf("nb_of_philos: %d\n", philos.nb_of_philos);
    printf("time to die: %d\n", philos.time_do_die);
    printf("time to eat: %d\n", philos.time_to_eat);
    printf("time_to_sleep: %d\n", philos.time_to_sleep);
    if (philos.nb_times_eat > 0)
        printf("nb_of_times: %d\n", philos.nb_times_eat);
    printf("philo start time:%ld\n", philos.start_time);
    
}