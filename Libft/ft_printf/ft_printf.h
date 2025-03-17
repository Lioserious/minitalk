/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:54:11 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/14 15:02:02 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// printf
int	ft_putchar_mod(char c, int fd);
int	ft_putnbr_mod(int n, int fd);
int	ft_putchar_mod(char c, int fd);
int	ft_putnbr_unsigned(unsigned int n, int fd);
int	ft_print_x(unsigned int n, int fd);
int	ft_print_upper_x(unsigned int n, int fd);
int	ft_print_p(void *ptr);
int	ft_printf(const char *format, ...);
int	my_putchar(const char c);
int	*get_count(void);
int	my_putstr(const char *str);
int	ft_printf(const char *format, ...);

#endif