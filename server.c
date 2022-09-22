/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:14:00 by dperez-m          #+#    #+#             */
/*   Updated: 2022/09/22 21:12:14 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
struct s_ctrl	g_var;

void	test(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
 	if (g_var.scheck == 0)
	{
		getsize(signal);
		//write(1, "a\n", 2);
	}
	else
		{
		static	char	letter;

		if (signal == SIGUSR1 || signal == SIGUSR2)
			{
			g_var.lcheck += 1;
			letter <<= 1;
			}
		if (signal == SIGUSR1)
			letter += 1;

		if (g_var.lcheck == 8) //Modifico aqui
		{
			g_var.str[g_var.pos] = letter;
			g_var.pos++;
			g_var.lcheck = 0;
		}
		if (g_var.size == g_var.pos)
		{
			//write(1, "b\n", 2);
			g_var.str[g_var.pos] = '\0';
			ft_printf("%s", g_var.str);
			g_var.pos = 0;
			g_var.scheck = 0;
			g_var.size = 0;
			free(g_var.str);
		}
	}
}

void	getsize(int signal)
{
	if (signal == SIGUSR2)
		g_var.size++;
	else if (signal == SIGUSR1)
	{
		//ft_printf("Size: %i", g_var.size);
		g_var.str = malloc(sizeof(char) * (g_var.size + 1));
		if (!g_var.str)
		{
			ft_printf("Error: Couldn't allocate memory\n");
			exit(1);
		}
		g_var.scheck = 1;
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