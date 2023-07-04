/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:18:50 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/04 13:34:24 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



void    start_info(t_data *info, int ac, char **args)
{
    info->nb_of_philos = ft_atoi(args[1]);
    info->time_do_die = (uint64_t) ft_atoi(args[2]);
    info->time_to_eat = (uint64_t) ft_atoi(args[3]);
    info->time_to_sleep = (uint64_t) ft_atoi(args[4]);
    if (ac == 6)
        info->nb_times_eat = ft_atoi(args[5]); 
    else
        info->nb_times_eat = -1;
    info->start_time = get_time();      
    
}

void    init_philos_thread(t_data *info)
{
    int     i;
    int     ph_nb;

    i = 0;
    ph_nb = info->nb_of_philos;
    while (i < ph_nb)
    {
        pthread_create(&info->threads_ph[i], NULL, &function, &info->philos[i])
    }    
}

int    start_philo(int ac, char **args)
{
    t_data     *info;
    
    info = malloc(sizeof(t_data));
    start_info(info, ac, args);
    init_philos_thread(&info);
    //print_philos(*info);
    

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