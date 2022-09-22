/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:14:00 by dperez-m          #+#    #+#             */
/*   Updated: 2022/09/22 19:53:22 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void	getsize(int signal);

struct s_ctrl	g_info;

void	test(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (g_info.scheck == 0)
		getsize(signal);
	static	char	letter;

	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		g_info.lcheck += 1;
		letter <<= 1;
	}
	if (signal == SIGUSR1)
		letter += 1;
	if (g_info.lcheck == 8)
	{
		g_info.str[g_info.strpos] = letter;
		if (letter == 0)
		{
			g_info.str[g_info.strpos + 1] = '\0';
			g_info.strpos = -1;
			printf("%s", g_info.str);
			g_info.size = 0;
			g_info.scheck = 0;
			free(g_info.str);
		}
		g_info.strpos++;
		g_info.lcheck = 0;
	}
}

void	getsize(int signal)
{
	if (signal == SIGUSR1)
		g_info.size += 1;
	else
	{
		g_info.str = malloc(sizeof(char) * (g_info.size + 1)); //Añado el +1 para el \0
		if (!g_info.str)
		{
			ft_printf("Error: Couldn't allocate memory\n");
			exit(1);
		}
		g_info.scheck = 1;
	}
}

int	main(void)
{
	struct sigaction	set;
	int					id;

	id = getpid();
	ft_printf("PID: %i\n", id);
	sigemptyset(&set.sa_mask);
	set.sa_flags = 0;
	set.sa_sigaction = test;
	sigaction(SIGUSR1, &set, NULL);
	sigaction(SIGUSR2, &set, NULL);
	while (1)
		pause();
	return (0);
}
