/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:21:49 by dperez-m          #+#    #+#             */
/*   Updated: 2022/09/22 22:26:52 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<stdio.h>
# include<unistd.h>
# include<signal.h>
# include<stdlib.h>
# include "./printf/ft_printf.h"

int		ft_atoi(const char *str);
void	getsize(int signal);
int		ft_atoiaux(char *str);
void	strprint(void);
typedef struct s_ctrl
{
	int		lcheck;
	int		scheck;
	int		size;
	char	*str;
	int		pos;
}		t_ctrl;
#endif