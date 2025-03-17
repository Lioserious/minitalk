/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:56:04 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/20 12:23:36 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_empty(void)
{
	char	*empty_str;

	empty_str = (char *)malloc(1);
	if (empty_str == NULL)
		return (NULL);
	empty_str[0] = '\0';
	return (empty_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*substring;

	i = 0;
	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (return_empty());
	if (len > str_len - start)
		len = str_len - start;
	substring = (char *)ft_calloc(len + 1, sizeof(char));
	if (substring == NULL)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}
