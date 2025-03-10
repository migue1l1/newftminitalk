/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:28:09 by pde-cast          #+#    #+#             */
/*   Updated: 2025/01/06 01:33:58 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	flag2;
	int	c;

	ret = 0;
	flag2 = 1;
	c = 0;
	while (nptr[c] == 32 || (nptr[c] >= 9 && nptr[c] <= 13))
		c++;
	if (nptr[c] == '-' || nptr[c] == '+')
	{
		if (nptr[c] == '-')
			flag2 = -1;
		c++;
	}
	while (nptr[c] != '\0' && ft_isdigit(nptr[c]))
	{
		ret = ret * 10 + (nptr[c] - '0');
		c++;
	}
	return (ret * flag2);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	send_bit(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_bit(pid, argv[2][i]);
			i++;
		}
		send_bit(pid, '\0');
	}
	else
	{
		ft_printf("error\n");
		return (1);
	}
	return (0);
}
