/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:15:20 by moaks             #+#    #+#             */
/*   Updated: 2026/09/09 20:17:41 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(long long n);
int		ft_printf(const char *format, ...);
int		ft_puthex(unsigned long long int i, char *digit, size_t base);
int		ft_pointer(void *pointer);
int		ft_unsigned_hex(unsigned int i, char *digit, size_t base);

#endif