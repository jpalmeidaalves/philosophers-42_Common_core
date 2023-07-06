/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:12:16 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/05 20:52:30 by joaoalme         ###   ########.fr       */
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

typedef struct s_philo
{
    pthread_t   *threads_ph;
    int     *right_fork;
    int     *left_fork;
} t_philo;

typedef struct s_data
{
    int         index;
    int         nb_of_philos;
    int         nb_rounds;
    int         time_do_die;
    int         time_to_eat;
    int         time_to_sleep;
    int         *forks;
    uint64_t    start_time;
    pthread_mutex_t     print_mutex;
    t_philo     philo;
    
}   t_data;

//philo.
void    *function(void *arg);

//check_input.c
int     check_input(int ac, char **av);

//debug.c
void    print_philos(t_data philos);

//time_related.c
uint64_t    get_time(void);
uint64_t    elapsed_time(t_data *info);

//utils.c
long	ft_atol(const char *nptr);
int	ft_atoi(const char *nptr);

//starting
void    start_info(t_data *info, int ac, char **args);
void    init_philos_thread(t_data *info);
void    init_forks(t_data *info);



#endif