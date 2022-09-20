/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:14:00 by dperez-m          #+#    #+#             */
/*   Updated: 2022/09/20 17:17:32 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
t_ctrl	g_info;

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	test(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	static	char	letter;
	//char		fletter;
	if (g_info.checksize == 0)
		getsize(signal);
	else
	{
		//static	int	letter;
		//char		fletter;

		if (signal == SIGUSR1 || signal == SIGUSR2)
			{
			g_info.lcheck++;
			letter <<= 1;
			}
		if (signal == SIGUSR1)
			letter += 1;

		if (g_info.lcheck == 7)
		{
			if (letter != '\0')
			g_info.str[g_info.strpos] = letter;
			else
				g_info.str[g_info.strpos] = '\0';
			ft_printf("%s\n", g_info.str);
			g_info.strpos++;
			g_info.lcheck = 0;
			if (letter == '\0')
				printstring();
		}
	}
	
	
}

void	printstring(void)
{
	ft_printf("%s", g_info.str);
	free(g_info.str);
	g_info.checksize = 0;
	g_info.size = 0;
}
void	getsize(int signal)
{
	if (signal == SIGUSR2)
		g_info.size++;
	else
	{
		ft_printf("Tamaño del size: %i\n", g_info.size);
		g_info.checksize = 1;
		g_info.str = malloc(sizeof(char) * (g_info.size + 1));
		if (g_info.str == NULL)
		{
			ft_printf("Error: Couldn't allocate memory\n");
			exit(1);
		}
		ft_bzero(g_info.str, g_info.size);
		g_info.size = 0;
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