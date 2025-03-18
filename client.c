/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:24 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/18 17:00:24 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// SIGUSR 2 = 1
// SIGUSR 1 = 0

void	character_to_binary(char t, pid_t server_pid)
{
	int	i;
	int	bit_value;

	i = 7;
	while (i >= 0)
	{
		bit_value = (t >> i) & 1;
		if (bit_value == 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(200);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		y;
	pid_t	server_pid;
	
	i = 0;
	y = 2;
	if (argc != 3)
	{
		ft_printf("Usage: %s [server_pid] [message]\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid PID\n");
		exit(EXIT_FAILURE);
	}
	while (argv[2][i] != '\0')
	{
		character_to_binary(argv[2][i], server_pid);
		i++;
	}
	return (character_to_binary('\0', server_pid), 0);
}
