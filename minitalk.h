/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:21:49 by dperez-m          #+#    #+#             */
/*   Updated: 2022/09/21 19:14:19 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include "./printf/ft_printf.h"

int	ft_atoi(const char *str);

typedef struct s_ctrl
{
	int		lcheck;
	char	*str;
	int		strpos;
	int		scheck;
	int		size;
}		t_ctrl;

#endif