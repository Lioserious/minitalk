/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:49:08 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/20 13:53:14 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t nbr)
{
	size_t		i;
	char		*d;
	const char	*s = (const char *)src;

	i = 0;
	d = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < nbr)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// Der Zeiger d ist eine Kopie von dest, beide zeigen
// auf denselben Speicherbereich. Wenn du d[i] = s[i]
// machst, schreibst du in den Speicher, auf den dest
// zeigt, weil sie dieselbe Adresse haben. Daher kann
// dest zurückgegeben werden, da es weiterhin auf den
// Speicher mit den kopierten Daten zeigt.