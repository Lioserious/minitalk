/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:24 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/17 19:02:27 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

//SIGUSR 2 = 1
//SIGUSR 1 = 0 

void character_to_binary(char t, pid_t server_pid)
{
	int i;
	int bit_value;
	
	i = 7;
	while(i >= 0)
	{
		bit_value = (t >> i) & 1;
		if(bit_value == 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		i--;
	} 
}

main(int argc, char* argv[])
{
	int i;
	int y;
	int k;
	char temp;
	char buffer[9];

	while(argv[y][i] != '\0')
	{

	}
}
