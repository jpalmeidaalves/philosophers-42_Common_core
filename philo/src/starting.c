/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:04:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/07 17:18:27 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    init_philos_thread(t_data *info)
{
    int i;

    info->philo = malloc(sizeof(int) * info->nb_of_philos);
    i = 0;
    while (i < info->nb_of_philos)
    {
        pthread_create(&info->philo[i].threads_ph, NULL, &debug_function, (void *)info);
        info->philo->id = i + 1;
        info->philo->last_meal = elapsed_time(info);
        printf("thread %d created\n", info->philo->id);
        i++;
    }
}

void    join_thread(t_data *info)
{
    int i;

    i = 1;
    while (i <= info->nb_of_philos)
    {
        pthread_join(info->philo[i].threads_ph, NULL);
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
    info->forks = NULL;
    info->start_time = get_time();
    info->var = 0;
    info->ph_muts = NULL;
    info->philo = NULL;
    info->died = 0;
}
void    init_ph_muts(t_data *info)
{
    int i;
    
    info->ph_muts = malloc(sizeof(pthread_mutex_t) * info->nb_of_philos);
    i = -1;
    while (++i < info->nb_of_philos)
        pthread_mutex_init(&info->ph_muts[i], NULL);
    
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