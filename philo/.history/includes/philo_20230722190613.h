/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:12:16 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/22 19:06:13 by joaoalme         ###   ########.fr       */
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
    int                 nb_of_philos;
    unsigned long       time_do_die;
    unsigned long       time_to_eat;
    unsigned long       time_to_sleep;
    int                 total_rounds;
    unsigned long       start_time;
    int                 end_of_simulation; //stop
    int                 first_round;
    pthread_mutex_t     print;
    pthread_mutex_t     check_end; //dead
}       t_data;

typedef struct s_philo
{
    int     id;
    pthread_mutex_t     *right_fork;
    pthread_mutex_t     left_fork;
    unsigned long       last_meal;
    int                 nb_meals;
    // int                 r_fork;
    // int                 l_fork;
    pthread_t           th_ph;
    t_data              *info;
}       t_philo;

//philo.
void    *routine(void *arg);
void    *debug_function(void *arg);
//void    sleeping(t_philo *philo);


//check_input.c
int     check_input(int ac, char **av);

//debug.c
void    print_philos(t_data philos, t_philo philo);

//time_related.c
unsigned long    get_time(void);
unsigned long    elapsed_time(t_data *info);
void     milisleep(unsigned int nb);
int	check_death(t_philo *ph);

//utils.c
int	ft_atoi(const char *nptr);

//starting
void    start_info(t_data *info, int ac, char **args);
void    init_philo(t_data *info, t_philo **philo);
int    start_philos_threads(t_data *info, t_philo *ph);

//clear.c
void    free_struct(t_data *info);

//monitor.c
void    *monitor(void *arg);

#endif