/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/18 14:54:30 by lihrig           ###   ########.fr       */
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
	(void)context;
}