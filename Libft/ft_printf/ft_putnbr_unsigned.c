/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:53:45 by lihrig            #+#    #+#             */
/*   Updated: 2024/11/05 17:32:08 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	char	nbr;

	if (n == 0)
	{
		if (my_putchar('0') == -1)
			return (-1);
		return (1);
	}
	if (n > 9)
	{
		if (ft_putnbr_unsigned(n / 10, fd) == -1)
			return (-1);
	}
	nbr = (n % 10) + '0';
	return (my_putchar(nbr));
}
