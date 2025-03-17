/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:15:45 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/17 16:13:48 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	parse_integers(const char *str, size_t *i)
{
	double	result;

	result = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	parse_decimals(const char *str, size_t *i)
{
	double	decimal;
	double	factor;

	decimal = 0.0;
	factor = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			decimal += (str[*i] - '0') * factor;
			factor *= 0.1;
			(*i)++;
		}
	}
	return (decimal);
}

double	ft_atof(const char *str)
{
	double	result;
	int		vrz;
	size_t	i;

	result = 0.0;
	vrz = 1;
	i = 0;
	if (str[i] == '-')
	{
		vrz = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = parse_integers(str, &i);
	result += parse_decimals(str, &i);
	return (result * vrz);
}
