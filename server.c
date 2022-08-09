/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:14:00 by dperez-m          #+#    #+#             */
/*   Updated: 2022/08/09 18:10:58 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	test(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	if (signal == SIGUSR1)
		ft_printf("SIGUSR1 recibido!\n");
	else if (signal == SIGUSR2)
		ft_printf("SIGUSR2 recibido!\n");
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