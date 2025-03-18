/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/18 15:12:39 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void print_message(char message[262144])
{
	int i;
	
	i = 0;
	while(message[i] != NULL)
	{
		write(1, &message[i], 1);
		i++;
	}
}
void signal_to_output(int sig, siginfo_t *info, void *context)
{
	static char bit = 0;
	static int count = 0;
	static int index = 0;
	static char message[262144];
	pid_t	client_pid;
	
	(void)context;
	if(sig == SIGUSR1)
		bit = (bit << 1) | 0;
	else if(sig == SIGUSR2)
		bit = (bit << 1) | 1;
	count++;
	if(count < 8)
	{	
		message[index] = bit;
		index++;
			if(message[index] == '\0')
				print_message(message);
		count = 0;
		bit = 0;
	}
}
