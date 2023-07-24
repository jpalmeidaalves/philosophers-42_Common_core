/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:04:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/22 19:36:53 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void     check_mutex_init(pthread_mutex_t *mut)
{
    int     result;
    
    result = pthread_mutex_init(&mut, NULL);
    if (result > 0)
        printf("Mutex init fail\n");
}

void    init_philo(t_data *info, t_philo *philo)
{
    int     i;
    
    i = -1;
    while (++i < info->nb_of_philos)
    {
        philo[i].id = i + 1;
        philo[i].last_meal = 0;
        philo[i].nb_meals = 0;
        check_mutex_init(&philo[i].left_fork);
        // pthread_mutex_init(&philo[i].left_fork, NULL);
        philo[i].l_fork = 0;
        philo[i].right_fork = NULL;
        philo[i].r_fork = NULL;
        philo[i].info = info;
        if (i == info->nb_of_philos - 1)
            philo[i].right_fork = &philo[0].left_fork;
        else
            philo[i].right_fork = &philo[i + 1].left_fork;
    }
}

void    start_info(t_data *info, int ac, char **args)
{
    info->nb_of_philos = ft_atoi(args[1]);
    info->time_do_die = (unsigned long)ft_atoi(args[2]);
    info->time_to_eat = (unsigned long)ft_atoi(args[3]);
    info->time_to_sleep = (unsigned long)ft_atoi(args[4]);
    if (ac == 6)
        info->total_rounds = ft_atoi(args[5]);
    else
        info->total_rounds = -1;
    info->start_time = 0;
    info->end_of_simulation = 0;
    info->first_round = 0;
    pthread_mutex_init(&info->check_end, NULL);
    pthread_mutex_init(&info->print, NULL);
    
    // check_mutex_init(info->print);    
    // check_mutex_init(info->check_end);    
}

int    start_philos_threads(t_data *info, t_philo *ph)
{
    int i;
    unsigned long   t;
    pthread_t   check_dead;
    
    i = -1;
    t = get_time();
    info->start_time = t;
    while (++i < info->nb_of_philos)
        ph[i].last_meal = t;
    i = -1;
    if (pthread_create(&check_dead, NULL, monitor, (void *)ph) != 0)
        return (0);
    while (++i < info->nb_of_philos)
    {
        if(pthread_create(&ph[i].th_ph, NULL, routine, (void *)&ph[i]) !=0)
            return (0);
    }
    i = -1;
    while (i++ < info->nb_of_philos)
        pthread_join(ph[i].th_ph, NULL);
    pthread_join(check_dead, NULL);
    return (1);
}

