/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-m <dperez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:15:32 by dperez-m          #+#    #+#             */
/*   Updated: 2022/09/20 15:25:26 by dperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] == '\n'
				|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
				|| str[i] == '\r')))
		i++;
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

/* void	chartobin(char letter)
{
	int mask = 1 << 7;

	while (mask != 0) {
		if (letter & mask)
			printf("1");
		else 
			printf("0");
		mask >>= 1;
	}
	printf("\n");

}

int	main(int argc, char **argv)
{
	for (int i = 0; argv[1][i]; i++)
	{
		chartobin(argv[1][i]);
	}		

	return (0);
} */