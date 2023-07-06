/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:04:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/06 15:20:18 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    init_philos_thread(t_data *info)
{
    int i;

    i = 1;
    while (i <= info->nb_of_philos)
    {
        pthread_create(&info->philo[i].threads_ph, NULL, &function, (void *)info);
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
        pthread_join(info->philo[i].threads_ph, NULL);
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
    info->philo = malloc(sizeof(t_philo) * info->nb_of_philos);
}
void    init_forks(t_data *info)
{
    int     i;

    i = 0;
    while (++i <= info->nb_of_philos)
        info->forks[i] = i;
    i = 0;
    while (++i <= info->nb_of_philos)
        info->philo[i].right_fork = info->forks[i];
    i = 0;
    while (++i <= info->nb_of_philos)
    {
        if (i == 1)
            info->philo[i].left_fork = &info->forks[info->nb_of_philos];
        else
            info->philo[i].left_fork = &info->forks[i - 1];
    }
    i = 0;
    while(++i <= info->nb_of_philos)
    {
        printf("right fork %d\n", *info->philo->right_fork);
    }
}