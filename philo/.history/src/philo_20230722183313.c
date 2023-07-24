/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:18:50 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/22 18:33:13 by joaoalme         ###   ########.fr       */
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

int     cleaning(t_data *info, t_philo *ph)
{
    int     i;
    
    i = -1;
    while (++i < info->nb_of_philos)
        pthread_mutex_destroy(&ph[i].left_fork);
    pthread_mutex_destroy(&info->print);
    pthread_mutex_destroy(&info->check_end);
    if (ph)
        free(ph);
    return (0);
}

void	one_philo(t_data *info)
{
	printf("0 1 has taken a fork\n");
	info->start_time = get_time();
	milisleep(info->time_do_die);
	printf("%ld 1 died!\n", get_time() - info->start_time);
}


/* int    start_philo(int ac, char **args)
{
    t_data      info;
    t_philo     *philo;

    start_info(&info,ac, args);
    init_philo(&info, philo);
    if (info.nb_of_philos == 1)
        simulation_one(philo, &info);
    else
    {
        if(start_philos_threads(&info, &philo) == 0);
        {
            printf("Error creating threads\n");
            return (-1);
        }
    }
    return (0);
} */
int     main(int ac, char**av)
{
    t_data      info;
    t_philo     *philo;
    
    if (check_input(ac, av) < 0)
        return (-1);
    start_info(&info,ac, av);
    init_philo(&info, philo);
    if (info.nb_of_philos == 1)
        simulation_one(philo, &info);
    else
    {
        if(start_philos_threads(&info, &philo) == 0);
        {
            printf("Error creating threads\n");
            return (-1);
        }
    }
    cleaning(&info, philo);
    return (0);
}

