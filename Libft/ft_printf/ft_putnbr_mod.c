/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:11:09 by lihrig            #+#    #+#             */
/*   Updated: 2024/11/05 17:32:04 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_mod(int n, int fd)
{
	char	nbr;
	int		*count;

	count = get_count();
	if (n == -2147483648)
	{
		if (my_putstr("-2147483648") == -1)
			return (-1);
		return (1);
	}
	if (n < 0)
	{
		if (my_putchar('-') == -1)
			return (-1);
		n = -n;
	}
	if (n == 0)
		return (my_putchar('0'));
	if (n > 9)
		if (ft_putnbr_mod(n / 10, fd) == -1)
			return (-1);
	nbr = (n % 10) + '0';
	return (my_putchar(nbr));
}
