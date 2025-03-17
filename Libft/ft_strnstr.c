/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:23:20 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/15 14:19:19 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystick, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len == 0)
		return ((char *)haystick);
	while (i < len && haystick[i] != '\0')
	{
		j = 0;
		while (j < needle_len && haystick[i + j] == needle[j] && (i + j) < len)
			j++;
		if (j == needle_len)
			return ((char *)&haystick[i]);
		i++;
	}
	return (NULL);
}
