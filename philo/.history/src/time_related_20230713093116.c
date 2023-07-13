/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_related.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:58:59 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/13 09:31:16 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void     milisleep(unsigned int nb)
{
    usleep(nb * 1000);
}

uint64_t    get_time(void)
{
    struct timeval  t1;

    gettimeofday(&t1, NULL);
    return ((t1.tv_sec * (uint64_t)1000) + t1.tv_usec / 1000);

}

uint64_t    elapsed_time(t_data *info)
{
    return (get_time() - info->start_time);
}

