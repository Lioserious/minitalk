/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:29:38 by lihrig            #+#    #+#             */
/*   Updated: 2024/11/05 18:02:02 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_prefix(void)
{
	int	*count;

	count = get_count();
	if (write(1, "0x", 2) == -1)
		return (-1);
	*count = *count + 2;
	return (1);
}

static int	ft_print_p_depth(void *ptr, int max_depth)
{
	char			nbr;
	unsigned long	adress;

	adress = (unsigned long long)ptr;
	if (max_depth == 16)
	{
		if (print_hex_prefix() == -1)
			return (-1);
	}
	if (adress == 0)
	{
		my_putchar('0');
		return (1);
	}
	if (max_depth <= 0)
		return (1);
	if (adress >= 16)
		ft_print_p_depth((void *)(adress / 16), max_depth - 1);
	nbr = (adress % 16);
	if (nbr < 10)
		nbr += '0';
	else
		nbr += 'a' - 10;
	return (my_putchar(nbr));
}

int	ft_print_p(void *ptr)
{
	int	*count;

	count = get_count();
	if (ft_print_p_depth(ptr, 16) == -1)
		return (-1);
	return (*count);
}
