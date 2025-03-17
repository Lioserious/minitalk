/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:24 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/17 17:35:45 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void character_to_binary(char t, char *binary)
{
	binary[8] = '\0';
	int i;
	int bit_value;
	
	i = 7;
	while(i >= 0)
	{
		bit_value = (t >> i) & 1;
		if(bit_value == 1)
			binary[7-i] = '1';
		else
			binary[7-i] = '0';
		i--;
	} 
}
