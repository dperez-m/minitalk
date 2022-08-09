/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:06:20 by dperez-m          #+#    #+#             */
/*   Updated: 2022/08/09 18:27:04 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] == '\n'
				|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
				|| str[i] == '\r')))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
		return (0);
	return (number * sign);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf("Error: Invalid PID");
		return (0);
	}
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	return (0);
}