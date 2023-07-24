/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rountine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:01:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/22 20:21:41 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void     print_action(t_philo *ph, char *action)
{
	pthread_mutex_lock(&ph->info->check_end);
	if (ph->info->end_of_simulation)
	{
		pthread_mutex_unlock(&ph->info->check_end);
		return ;
	}
	pthread_mutex_lock(&ph->info->print);
	printf("%ld %d %s\n", elapsed_time(ph->info), ph->id, action);
	pthread_mutex_unlock(&ph->info->print);
	pthread_mutex_unlock(&ph->info->check_end);
}

static void    sleeping(t_philo *philo)
{
    int     sleep_time;
    
    sleep_time = philo->info->time_to_sleep;
	print_action(philo, "is sleeping");
	milisleep(sleep_time);
	print_action(philo, "is thinking");
	usleep(500);
}
static void	eat_odd(t_philo *ph)
{
	pthread_mutex_lock(ph->right_fork);
	pthread_mutex_lock(&ph->left_fork);
	print_action(ph, "has taken a fork");
	print_action(ph, "has taken a fork");
	print_action(ph, "is eating");
	pthread_mutex_lock(&ph->info->check_end);
	ph->last_meal = get_time();
	ph->nb_meals++;
	pthread_mutex_unlock(&ph->info->check_end);
	milisleep(ph->info->time_to_eat);
	pthread_mutex_unlock(&ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	sleeping(ph);
}

static void	eat_even(t_philo *ph)
{		
	pthread_mutex_lock(&ph->left_fork);
	pthread_mutex_lock(ph->right_fork);
	ph->*l_fork = 1;
	ph->r_fork = 1;
	print_action(ph, "has taken a fork");
	print_action(ph, "has taken a fork");
	print_action(ph, "is eating");
	pthread_mutex_lock(&ph->info->check_end);
	ph->last_meal = get_time();
	ph->nb_meals++;
	pthread_mutex_unlock(&ph->info->check_end);
	milisleep(ph->info->time_to_eat);
	0ph->l_fork = 0;
	ph->r_fork = 0;
	pthread_mutex_unlock(&ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	sleeping(ph);
}
 

void    *routine(void *arg)
{
    t_philo *philo;
    t_data  *info;

    philo = (t_philo *)arg;
    info = philo->info;
    while (1)
    {
        pthread_mutex_lock(&info->check_end);
        if (info->end_of_simulation == 1)
            break;
        pthread_mutex_unlock(&info->check_end);
        if (philo->id % 2 == 0)
            eat_even(philo);
        else
            eat_odd(philo);
    }
    pthread_mutex_unlock(&info->check_end);
    return (NULL);
}

