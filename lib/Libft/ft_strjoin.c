/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:07:57 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/20 12:25:55 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str_len;
	size_t	i;
	size_t	l;
	char	*strjoin;

	i = 0;
	l = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)ft_calloc(str_len + 1, sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[l] != '\0')
		strjoin[i++] = s2[l++];
	return (strjoin);
}
