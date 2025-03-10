/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:48:45 by pde-cast          #+#    #+#             */
/*   Updated: 2025/01/06 01:18:13 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

char	*alt_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		c1;
	int		c2;
	int		c3;

	c1 = 0;
	c2 = 0;
	c3 = 0;
	if (!s1 && !s2)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ret)
		return (NULL);
	while (s1[c1] != '\0')
	{
		ret[c3] = s1[c1];
		c1++;
		c3++;
	}
	while (s2[c2] != '\0')
		ret[c3++] = s2[c2++];
	ret[c3] = '\0';
	return (ret);
}

void	bit_handler(int signal)
{
	static char	i;
	static int	bit;
	static char	*message = NULL;
	i = '\0';
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{	
		message = alt_strjoin(message, &i);
		if (i == '\0')
		{
			ft_printf("%s", message);
			ft_printf("%c", '\n');
			memset(message, 0, ft_strlen(message));
		}
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error, try: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for message\n");
	while (argc == 1)
	{
		signal(SIGUSR1, bit_handler);
		signal(SIGUSR2, bit_handler);
		pause ();
	}
	return (0);
}
