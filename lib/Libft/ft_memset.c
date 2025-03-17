/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:43:56 by lihrig            #+#    #+#             */
/*   Updated: 2024/10/14 16:22:45 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <string.h>

void	*ft_memset(void *ptr, int value, size_t nbr)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < nbr)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

// void *: Der Parameter void *ptr ermöglicht es der Funktion,
// einen Zeiger auf einen beliebigen Datentyp zu akzeptieren,
// wodurch die Funktion universell für verschiedene Datentypen wie char,
// int, oder float verwendet werden kann, ohne dass eine spezifische
// Typisierung erforderlich ist.

// unsigned char: Die Verwendung von unsigned char für den Zeiger p und
// die Umwandlung des int value in unsigned char stellen sicher,
// dass der Speicher byteweise gefüllt wird, da ein char genau 1 Byte
// entspricht und die Werte im Bereich von 0 bis 255 liegen, was für
// die meisten Speicheroperationen erforderlich ist.

// Flexibilität und Speicherzugriff: Diese Kombination ermöglicht es,
// den Speicher flexibel und effizient zu manipulieren, indem void *
// die allgemeine Datenstruktur unterstützt und unsigned char die genaue
// Kontrolle über die einzelnen Bytes im Speicher gewährleistet.

// int main (void)
// {
//     char buffer[20];
//     ft_memset(buffer, 'A', 10);
//     buffer[10] = '\0';
//     printf("Buffer nach ft_memset: %s\n", buffer);
//     char buffer2[20];
//     memset(buffer2, 'B', 10);
//     buffer2[10] = '\0';
//     printf("Buffer nach ft_memset: %s\n", buffer2);
//     return (0);
// }