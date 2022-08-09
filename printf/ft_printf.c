/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:25:30 by dperez-m          #+#    #+#             */
/*   Updated: 2022/02/08 14:59:06 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	write_p(unsigned long int args)
{
	if (args < 16)
	{
		if (args > 9)
		{
			args += 87;
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
		return (write_p(args / 16) + write_p(args % 16));
	}
	return (0);
}

int	checktype(const char *type, va_list args)
{
	int	len;

	len = 0;
	if (*type == 'c')
		len += write_c(va_arg(args, int));
	if (*type == 's')
		len += write_s(va_arg(args, char *));
	if (*type == 'p')
	{
		write(1, "0x", 2);
		len += 2 + write_p(va_arg(args, unsigned long int));
	}
	if (*type == 'd' || *type == 'i')
		len += write_di(va_arg(args, int));
	if (*type == 'u')
		len += write_u(va_arg(args, unsigned int));
	if (*type == 'x')
		len += write_x(va_arg(args, unsigned int), 87);
	if (*type == 'X')
		len += write_x(va_arg(args, unsigned int), 55);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;
	int		x;

	va_start(args, str);
	x = -1;
	len = 0;
	while (str[++x] != '\0')
	{
		if (str[x] == '%' && str[x + 1] != '%')
			len += checktype(&str[++x], args);
		else if (str[x] == '%' && str[x + 1] == '%')
		{
			write(1, "%", 1);
			x++;
			len++;
		}
		else
		{
			write(1, &str[x], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
