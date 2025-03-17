/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:10:41 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/16 12:20:37 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	vrz;

	i = 0;
	nbr = 0;
	vrz = 1;
	while (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			vrz = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * vrz);
}
