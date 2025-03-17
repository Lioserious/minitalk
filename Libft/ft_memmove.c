/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:08:46 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/20 12:12:44 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memcpy_forward(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, void *src, size_t len)
{
	char		*d;
	const char	*s = (const char *)src;
	size_t		i;

	d = (char *)dest;
	i = len;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (d > s)
	{
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
		ft_memcpy_forward(d, s, len);
	return (dest);
}

/*1. Check if src is the same as dest
  2. Check that there is no overlap and cpy from
		start to end
  3. There is overlap it cpy from behind to the start
  to prevent the change of source data
  */