/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:21:49 by dperez-m          #+#    #+#             */
/*   Updated: 2022/09/20 16:36:50 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include "./printf/ft_printf.h"

int		ft_atoi(const char *str);
void	getsize(int signal);
void	printstring(void);
void	ft_bzero(void *s, size_t n);

typedef struct s_ctrl
{
	int		checksize;
	int		size;
	int		lcheck;
	int		strpos;
	char	*str;

}	t_ctrl;

#endif