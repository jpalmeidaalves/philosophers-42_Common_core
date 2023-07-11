/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:18:50 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/11 11:50:23 by joaoalme         ###   ########.fr       */
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
} */
 
void    eat(t_data *info, t_philo *philo)
{
    int     id;
    
    id = philo->id;
    pthread_mutex_lock(&info->philo_muts[id -1]);
    if (info->forks[id - 1] == 0)
    {
        info->forks[id -1] = 1;
        philo->right_fork = 1;
    }
    else if (info->forks[id] == 0)
    {
        info->forks[id] = 1;
        philo->left_fork = 1;
    }
    if (philo->left_fork && philo->right_fork)
    {
        printf("")
        ft_usleep(info->time_to_eat);
    }
    pthread_mutex_unlock(&info->philo_muts[id -1]);
}
 
void    *routine(void *arg)
{
    t_data  *info;
    t_philo *philo;

    info = (t_data *)arg;
    philo = info->philo;
    while (1)
    {
        eat(info, philo);
        // sleep
        // think  
    }
    
    
}

int    start_philo(int ac, char **args)
{
    t_data     info;
    
    start_info(&info, ac, args);
    init_ph_muts(&info);
    init_forks(&info);
    init_philos_thread(&info);
    print_philos(info);
    join_thread(&info);
    printf("debug result: %d\n", info.var);
    
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

