/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:12:16 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/04 13:33:53 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_data
{
    int         nb_of_philos;
    uint64_t    time_do_die;
    uint16_t    time_to_eat;
    uint64_t    time_to_sleep;
    int         nb_times_eat;
    uint64_t    start_time;
    pthread_t   *threads_ph;
    t_philo     *philos;
    
}   t_data;

//check_input.c
int     check_input(int ac, char **av);

//debug.c
void    print_philos(t_data philos);

//time_related.c
uint64_t    get_time(void);
uint64_t    elapsed_time(t_data ph);


#endif