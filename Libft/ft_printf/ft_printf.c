/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:44:24 by lihrig            #+#    #+#             */
/*   Updated: 2024/11/05 17:48:10 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	search_for_case(char c, va_list args)
{
	int	*count;
	int	temp;

	count = get_count();
	if (c == 'c')
		temp = my_putchar(va_arg(args, int));
	else if (c == 's')
		temp = my_putstr(va_arg(args, char *));
	else if (c == 'p')
		temp = ft_print_p(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		temp = ft_putnbr_mod(va_arg(args, int), 1);
	else if (c == 'u')
		temp = ft_putnbr_unsigned(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		temp = ft_print_x(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		temp = ft_print_upper_x(va_arg(args, unsigned int), 1);
	else if (c == '%')
		temp = my_putchar('%');
	else
		return (-1);
	if (temp == -1)
		return (-1);
	return (*count);
}

int	process_specifier(char specifier, va_list args)
{
	int	result;

	result = search_for_case(specifier, args);
	if (result < 0)
		return (-1);
	return (result);
}

int	handle_format(const char *format, va_list args)
{
	int	i;
	int	*count;

	i = 0;
	count = get_count();
	*count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (process_specifier(format[i], args) < 0)
				return (-1);
		}
		else
		{
			if (my_putchar(format[i]) < 0)
				return (-1);
		}
		i++;
	}
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	if (!format)
		return (0);
	va_start(args, format);
	result = handle_format(format, args);
	va_end(args);
	return (result);
}
// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		*count;

// 	count = get_count();
// 	*count = 0;
// 	if (!format)
// 		return (0);
// 	i = 0;
// 	va_start(args, format);
// 	while (format[i] != '\0')
// 	{
// 		if (format[i] == '%' && format[i + 1] != '\0')
// 		{
// 			i++;
// 			if (search_for_case(format[i], args) < 0)
// 				return (va_end(args), -1);
// 		}
// 		else
// 		{
// 			if (my_putchar(format[i]) < 0)
// 				return (va_end(args), -1);
// 		}
// 		i++;
// 	}
// 	va_end(args);
// 	return (*get_count());
// }

// int	main(void)
// {
// 	int		i;
// 	char	d;

// 	i = ft_printf("%d", "");
// 	printf("\n%d", );
// 	// d = i + '0';
// 	// write(1, &d, 1);
// 	return (0);
// }
