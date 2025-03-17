/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:55:48 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/20 12:36:36 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

void	*ft_calloc(size_t nbr_elements, size_t size_of_elements)
{
	size_t	total_size;
	void	*ptr;

	total_size = nbr_elements * size_of_elements;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, '\0', total_size);
	return (ptr);
}

// int	main(void)
// {
// 	int *arr;
// 	int i;

// 	// Verwendung der eigenen calloc-Implementierung
// 	arr = (int *)ft_calloc(5, sizeof(int));

// 	if (arr == NULL)
// 	{
// 		// Fehlerbehandlung, falls die Speicherallokation fehlschlägt
// 		return (1);
// 	}

// 	// Werte des Arrays ausgeben (alle sollten 0 sein)
// 	for (i = 0; i < 5; i++)
// 	{
// 		printf("arr[%d] = %d\n", i, arr[i]);
// 	}

// 	// Allokierten Speicher freigeben
// 	free(arr);

// 	return (0);
// }