/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:18:50 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/12 21:07:51 by joaoalme         ###   ########.fr       */
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
}
  */

void    eat(t_data *info, t_philo *philo)
{
    int     i;

    i = philo->id - 1;
    pthread_mutex_lock(&info->philo_muts[i]);
    if (i == 0)
    {
        if(info->forks[info->nb_of_philos - 1] == 0)
        {
            info->forks[info->nb_of_philos - 1] = 1;
            philo->right_fork = 1;
            printf("%ldms %d has take righ fork\n",elapsed_time(info),philo->id);
        }
        if (info->forks[i] == 0)
        {
            info->forks[i] = 1;
            philo->left_fork = 1;
            printf("%ldms %d has take left fork\n",elapsed_time(info),philo->id);
        }
    }
    else 
    {
        if (info->forks[i - 1] == 0)
        {            
            info->forks[i - 1] = 1;
            philo->right_fork = 1;
            printf("%ldms %d has take righ fork\n", elapsed_time(info),philo->id);
        }
        if (info->forks[i] == 0)
        {
            info->forks[i] = 1;
            philo->left_fork = 1;
            printf("%ldms %d has take left fork\n", elapsed_time(info), philo->id);
        }
    }
    if (i == 0)
    {
        if (philo->right_fork && philo->left_fork)
        {
            printf("%ldms %d is eating\n", elapsed_time(info),philo->id);
            ft_usleep(info->time_to_eat);
            info->forks[info->nb_of_philos - 1] = 0;
            philo->right_fork = 0;
            printf("%ldms %d drop right fork\n",elapsed_time(info),philo->id);
            info->forks[i] = 0;
            philo->left_fork = 0;
            printf("%ldms %d drop left fork\n", elapsed_time(info),philo->id);
            sleeping(philo);
        }
    }
    else
    {    
        if (philo->right_fork && philo->left_fork)
        {
            printf("%ldms %d is eating\n", elapsed_time(info),philo->id);
            ft_usleep(info->time_to_eat);
            info->forks[i - 1] = 0;
            philo->right_fork = 0;
            printf("%ldms  %d drop right fork\n",elapsed_time(info),philo->id);
            info->forks[i] = 0;
            philo->left_fork = 0;
            printf("%ldms %d drop left fork\n", elapsed_time(info),philo->id);
            sleeping(philo);
        }
    }
    pthread_mutex_unlock(&info->philo_muts[i]);
}
 
void    sleeping(t_philo *philo)
{
    int sleep_time = philo->info->time_to_sleep;

    printf("%ldms %d is sleeping\n", elapsed_time(philo->info), philo->id);
    ft_usleep(sleep_time);
    printf("%ldms %d is thinking\n", elapsed_time(philo->info), philo->id);
}

void    *routine(void *arg)
{
    t_philo *philo;
    t_data  *info;

    philo = (t_philo *)arg;
    //printf("ph-id: %d\n" , philo->id); 
    info = philo->info;
    while (1)
    {
        // printf("ph-id: %d\n" , philo->id); 
        if (philo->id % 2 == 0 && !philo->info->first_round)
        {
            ft_usleep(1);
            philo->info->first_round = 1;
        }
        eat(info, philo);
        // sleeping(philo);
        // think  

    }
    
    
}

int    start_philo(int ac, char **args)
{
    t_data      info;
    t_philo     *philo;

    start_info(&info, ac, args);
    philo = malloc(sizeof(t_philo) * (info.nb_of_philos) );
    init_ph_muts(&info);
    init_forks(&info);

    init_philos_thread(&info, philo);
    // print_philos(info, *philo);
    //join_thread(philo, info);
    // printf("debug result: %d\n", info.var);
    
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

