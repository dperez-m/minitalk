/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:15:32 by dperez-m          #+#    #+#             */
/*   Updated: 2022/09/22 22:10:38 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	number;

	sign = 1;
	number = 0;
	i = ft_atoiaux((char *)str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
		return (0);
	return (number * sign);
}

int	ft_atoiaux(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] == '\n'
				|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
				|| str[i] == '\r')))
		i++;
	return (i);
}
