/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:20:02 by lihrig            #+#    #+#             */
/*   Updated: 2024/11/05 17:31:39 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_x(unsigned int n, int fd)
{
	char	nbr;
	int		i;

	i = 0;
	if (n == 0)
	{
		if (my_putchar('0') == -1)
			return (-1);
		return (1);
	}
	if (n >= 16)
	{
		if (ft_print_upper_x(n / 16, fd) == -1)
			return (-1);
	}
	nbr = (n % 16);
	if (nbr < 10)
		nbr += '0';
	else
		nbr += 'A' - 10;
	return (my_putchar(nbr));
}
