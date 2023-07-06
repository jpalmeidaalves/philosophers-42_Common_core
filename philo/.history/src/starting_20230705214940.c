/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:04:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/05 21:49:40 by joaoalme         ###   ########.fr       */
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
        printf("thread %d created\n", i);
        i++;
    }
}

void    start_info(t_data *info, int ac, char **args);
{
    info->index = 0;
    info->nb_of_philos = ft_atoi(args[1]);
    info->nb_rounds = ft_atoi(args[5]);
    info->time_do_die = 0;
    info->time_to_eat = 0;
    info->time_to_sleep = 0;
    info->forks = NULL;
    info->start_time = 0;
    info->var = 0;
    info->philo.threads_ph = NULL;
    info->philo.right_fork = NULL;
    info->philo.left_fork = NULL;
}