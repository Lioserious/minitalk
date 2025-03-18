/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:24 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/18 18:20:28 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// SIGUSR 2 = 1
// SIGUSR 1 = 0

void	argc_error(void)
{
	ft_printf("Usage: %s [server_pid] [message]\n");
	exit(EXIT_FAILURE);
}

void	server_response(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Server received message\n");
	exit(EXIT_SUCCESS);
}

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
	struct sigaction	sigact;
	int					i;
	pid_t				server_pid;

	sigact.sa_handler = server_response;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	i = 0;
	if (argc != 3)
		argc_error();
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
	{
		ft_printf("Failed to set up SIGUSR1 handler.\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		character_to_binary(argv[2][i], server_pid);
		i++;
	}
	character_to_binary('\0', server_pid);
	pause();
	return (0);
}
