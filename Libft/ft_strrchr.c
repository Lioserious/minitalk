/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:52:14 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/16 11:51:14 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)&s[s_len]);
	while (s_len > 0)
	{
		if (s[s_len - 1] == (char)c)
			return ((char *)&s[s_len - 1]);
		s_len--;
	}
	if ((char)c == s[0])
		return ((char *)&s[0]);
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str = "Hallo, Welt! Wie geht es dir?";
// 	int			ch;
// 	char		*result;

// 	ch = 'e';
// 	result = ft_strrchr(str, ch);
// 	if (result != NULL)
// 	{
// 		printf("Das letzte Vorkommen von '%c' ist bei Index: %ld\n", ch, result
// 			- str);
// 	}
// 	else
// 	{
// 		printf("Das Zeichen '%c' wurde nicht gefunden.\n", ch);
// 	}
// 	return (0);
// }
