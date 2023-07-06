/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:04:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/06 08:22:44 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    init_philos_thread(t_data *info)
{
    int i;

    i = 1;
    info->philo.threads_ph = malloc(sizeof(pthread_t) * info->nb_of_philos);
    while (i <= info->nb_of_philos)
    {
        pthread_create(&info->philo.threads_ph[i], NULL, &function, (void *)info);
        printf("thread %d created\n", i);
        i++;
    }
}

void    join_thread(t_data *info)
{
    int i;

    i = 1;
    while (i <= info->nb_of_philos)
    {
        pthread_join(info->philo.threads_ph[i], NULL);
        i++;
    }
}
void    start_info(t_data *info, int ac, char **args)
{
    (void)ac;
    info->index = 0;
    info->nb_of_philos = ft_atoi(args[1]);
    info->nb_rounds = ft_atoi(args[5]);
    info->time_do_die = ft_atoi(args[2]);
    info->time_to_eat = ft_atoi(args[3]);
    info->time_to_sleep = ft_atoi(args[4]);
    info->forks = malloc(sizeof(int) * info->nb_of_philos);
    info->start_time = get_time();
    info->var = 0;
    info->philo->threads_ph = malloc ;
}
void    init_forks(t_data *info)
{
    int     i;

    i = 0;
    while (++i <= info->nb_of_philos)
        info->forks[i] = 0;
    
}