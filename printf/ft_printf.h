/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:11:25 by dperez-m          #+#    #+#             */
/*   Updated: 2022/02/08 15:00:06 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdio.h>
# include<stdarg.h>
# include<unistd.h>

int	write_c(char args);
int	write_s(char *args);
int	write_di(int args);
int	write_u(unsigned int args);
int	write_x(unsigned int args, char type);
int	write_p(unsigned long int args);
int	checktype(const char *type, va_list args);
int	ft_printf(const char *str, ...);
#endif