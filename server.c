/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:14:00 by dperez-m          #+#    #+#             */
/*   Updated: 2022/08/17 14:23:25 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int	g_x = 0;

void	test(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	static	int	letter;

	if (signal == SIGUSR1 || signal == SIGUSR2)
		{
		g_x += 1;
		letter <<= 1;
		}
	if (signal == SIGUSR1)
		letter += 1;

	if (g_x == 8)
	{
		ft_printf("%c", (char)letter);
		g_x = 0;
	}
	
	
}

int	main()
{
	struct sigaction set;
	int id;

	id = getpid();
	ft_printf("PID: %i\n", id);
	sigemptyset(&set.sa_mask);
	set.sa_flags = 0;
	set.sa_sigaction = test;
	sigaction(SIGUSR1, &set, NULL);
	sigaction(SIGUSR2,&set, NULL);
	while (1)
		pause();
	return (0);
}