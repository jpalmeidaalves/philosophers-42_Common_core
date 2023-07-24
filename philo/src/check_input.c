/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:57:35 by joaoalme          #+#    #+#             */
/*   Updated: 2023/07/22 21:38:23 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_only_digit(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[++i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_input(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error: philo: Wrong number of arguments\n");
		return (-1);
	}
	if (!is_only_digit(av))
	{
		printf("Error: philo: Only numeric arguments allowed\n");
		return (-2);
	}
	return (0);
}
