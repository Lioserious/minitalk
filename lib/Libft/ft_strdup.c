/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:31:09 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/15 14:29:07 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*str1;

	len = ft_strlen(str) + 1;
	str1 = (char *)malloc(len);
	if (str1 != NULL)
		ft_strlcpy(str1, str, len);
	return (str1);
}
