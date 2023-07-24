/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:12:16 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/24 15:00:37 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				nb_of_philos;
	unsigned long	time_do_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				total_rounds;
	unsigned long	start_time;
	int				end_of_simulation;
	int				first_round;
	pthread_mutex_t	print;
	pthread_mutex_t	check_end;
}					t_data;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
	unsigned long	last_meal;
	int				nb_meals;
	int				*r_fork;
	int				l_fork;
	pthread_t		th_ph;
	t_data			*info;
}					t_philo;

//routine.c
void				*routine(void *arg);

//check_input.c
int					check_input(int ac, char **av);

//time_related.c
unsigned long		get_time(void);
unsigned long		elapsed_time(t_data *info);
void				milisleep(unsigned int nb);
int					check_death(t_philo *ph);

//utils.c
int					ft_atoi(const char *nptr);

philo.c
void				start_info(t_data *info, int ac, char **args);
void				init_philo(t_data *info, t_philo *philo);
int					start_philos_threads(t_data *info, t_philo *ph);

//clear.c
void				free_struct(t_data *info);

//monitor.c
void				*monitor(void *arg);

#endif
