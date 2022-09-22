/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:06:20 by dperez-m          #+#    #+#             */
/*   Updated: 2022/09/22 19:51:33 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendsignal(int pid, char letter)
{
	int	mask;

	mask = 1 << 7;
	while (mask != 0)
	{
		if (letter & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		mask >>= 1;
		usleep(80);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	x;

	if (argc != 3)
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
	x = -1;
	while (argv[2][++x] != '\0')
	{
		kill(pid, SIGUSR1);
		usleep(80);
	}
	kill(pid, SIGUSR2);
	x = -1;
	while (argv[2][++x] != '\0')
	{
		sendsignal(pid, argv[2][x]);
		usleep(50);
	}
	x = 9;
	while (--x > 0)
		kill(pid, SIGUSR2);
	return (0);
}
