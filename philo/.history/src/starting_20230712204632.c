/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:04:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/11 11:32:37 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    init_philos_thread(t_data *info, t_philo *philo)
{
    int i;

    philo = malloc(sizeof(t_philo) * info->nb_of_philos);
    i = 0;
    printf("nbfil %d\n", info->nb_of_philos);
    while (i < info->nb_of_philos)
    {
        philo[i].info = info;
        // pthread_create(&info->philo[i].threads_ph, NULL, debug_function, (void *)info);
        philo[i].id = i + 1;
        philo[i].last_meal = elapsed_time(info);
        philo[i].right_fork = 0;
        philo[i].left_fork = 0;
        pthread_create(&philo[i].threads_ph, NULL, routine, (void *)&philo[i]);
        // printf("thread %d created\n", philo[i].id);
        i++;
    }
    i = 0;
    while (i < info->nb_of_philos)
    {
        pthread_join(philo[i].threads_ph, NULL);
        i++;
    }
}


void    start_info(t_data *info, int ac, char **args)
{
    (void)ac;
    info->index = 0;
    info->nb_of_philos = ft_atoi(args[1]);
    info->time_do_die = ft_atoi(args[2]);
    info->time_to_eat = ft_atoi(args[3]);
    info->time_to_sleep = ft_atoi(args[4]);
    if (ac == 6)
        info->nb_rounds = ft_atoi(args[5]);
    else
        info->nb_rounds = -1;
    info->start_time = get_time();
    info->var = 0;
    info->philo_muts = NULL;
    info->died = 0;
    info->first_round = 0;
}

void    init_ph_muts(t_data *info)
{
    int i;
    
    info->philo_muts = malloc(sizeof(pthread_mutex_t) * info->nb_of_philos);
    i = 0;
    while (i < info->nb_of_philos)
    {
        pthread_mutex_init(&info->philo_muts[i], NULL);
        i++;
    }
    
}

void    init_forks(t_data *info)
{
    int     i;
    
    info->forks = malloc(sizeof(int) * info->nb_of_philos);
    i = 0;
    while (i < info->nb_of_philos)
    {
        info->forks[i] = 0;
        i++;
    }
}
