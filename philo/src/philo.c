/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:18:50 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/07 16:21:13 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *debug_function(void *arg)
{
    t_data  *info;

    int i = 0;    
    info = (t_data *)arg;
    while (i < 10000000)
    {
        pthread_mutex_lock(&info->ph_muts[4]);
        info->var++;
        pthread_mutex_unlock(&info->ph_muts[4]);
        i++;
    }
    return (NULL);
}
/* void    *simulation(void *)
{
    
} */

/* int     pick_forks(t_data *info)
{
    
} */


int    start_philo(int ac, char **args)
{
    t_data     *info;
    
    info = malloc(sizeof(t_data));
    //pthread_mutex_init(&info->print_mutex, NULL);
    start_info(info, ac, args);
    init_ph_muts(info);
    init_philos_thread(info);
    init_forks(info);
    print_philos(*info);
    join_thread(info);
    printf("debug result: %d\n", info->var);
    free(info);
    return (0);
}
int     main(int ac, char**av)
{
    if (check_input(ac, av) < 0)
        return (-1);
    start_philo(ac, av);    
    return (0);
}