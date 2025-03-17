/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myputchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:39:37 by lihrig            #+#    #+#             */
/*   Updated: 2024/11/05 15:40:40 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*get_count(void)
{
	static int	count = 0;

	return (&count);
}

int	my_putchar(const char c)
{
	int	*count;

	count = get_count();
	if (write(1, &c, 1) == -1)
		return (-1);
	*count = *count + 1;
	return (1);
}

int	my_putstr(const char *str)
{
	int	*count;

	count = get_count();
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*count = *count + 6;
		return (1);
	}
	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		*count = *count + 1;
		str++;
	}
	return (1);
}
