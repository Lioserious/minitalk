/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/18 17:20:21 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_error(void)
{
	ft_printf("ERROR with Signal");
	exit(EXIT_FAILURE);
}

void	print_message(char message[262144], int *index)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		write(1, &message[i], 1);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	while (i < 262144)
		message[i++] = '\0';
	*index = 0;
}

void	signal_to_output(int sig, siginfo_t *info, void *context)
{
	static char	bit = 0;
	static int	count = 0;
	static int	index = 0;
	static char	message[262144];
	pid_t		client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		bit = (bit << 1) | 0;
	else if (sig == SIGUSR2)
		bit = (bit << 1) | 1;
	count++;
	if (count == 8)
	{
		message[index] = bit;
		if (message[index] == '\0')
			print_message(message, &index);
		else
			index++;
		count = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;
	pid_t				pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigact.sa_sigaction = signal_to_output;
	sigact.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		sig_error();
	if (sigaction(SIGUSR2, &sigact, NULL) == -1)
		sig_error();
	while (1)
		pause();
	return (0);
}
