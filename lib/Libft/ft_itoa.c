/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:03:01 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/20 12:12:23 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	number_len(int n)
{
	int	numb;
	int	count;

	numb = n;
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (numb != 0)
	{
		numb = numb / 10;
		count++;
	}
	return (count);
}

static char	*reverse_string(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < (len / 2))
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	numb;
	int		i;
	char	*str;
	int		len;

	len = number_len(n);
	i = 0;
	numb = n;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (numb == 0)
		str[i] = '0';
	if (numb < 0)
	{
		numb = -numb;
		str[len - 1] = '-';
	}
	while (numb > 0 && i < len)
	{
		str[i++] = (numb % 10) + '0';
		numb = numb / 10;
	}
	return (reverse_string(str));
}
