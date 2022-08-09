/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:12:13 by dperez-m          #+#    #+#             */
/*   Updated: 2022/02/08 14:54:19 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<unistd.h>

int	write_c(char args)
{
	write(1, &args, 1);
	return (1);
}

int	write_s(char *args)
{
	int	x;

	x = 0;
	if (args == NULL)
		return (write(1, "(null)", 6));
	while (args[x] != '\0')
	{
		write(1, &args[x], 1);
		x++;
	}
	return (x);
}

int	write_di(int args)
{
	if (args == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (args < 0)
	{
		write(1, "-", 1);
		args = -args;
		return (1 + write_di(args));
	}
	if (args < 10)
	{
		args += '0';
		write(1, &args, 1);
		return (1);
	}
	else
	{
		return (write_di(args / 10) + write_di(args % 10));
	}
	return (0);
}

int	write_u(unsigned int args)
{
	if (args < 10)
	{
		args += '0';
		write(1, &args, 1);
		return (1);
	}
	else
	{
		return (write_di(args / 10) + write_di(args % 10));
	}
	return (0);
}

int	write_x(unsigned int args, char type)
{
	if (args < 16)
	{
		if (args > 9)
		{
			args += type;
			write(1, &args, 1);
			return (1);
		}
		else
		{
			args += '0';
			write(1, &args, 1);
			return (1);
		}
	}
	else
	{
		return (write_x(args / 16, type) + write_x(args % 16, type));
	}
	return (0);
}
