/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:39:08 by moaks             #+#    #+#             */
/*   Updated: 2026/09/09 20:13:39 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_specifier(char specifier, va_list args)
{
	if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 'i' || specifier == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'x')
		return (ft_unsigned_hex(va_arg(args, int), "0123456789abcdef", 16));
	else if (specifier == 'X')
		return (ft_unsigned_hex(va_arg(args, int), "0123456789ABCDEF", 16));
	else if (specifier == 'u')
		return (ft_unsigned_hex(va_arg(args, int), "0123456789", 10));
	else if (specifier == 'p')
		return (ft_pointer(va_arg(args, void *)));
	else if (specifier == 'f')
		return (ft_double(va_arg(args, double)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	size_t	size;
	va_list	args;

	va_start(args, format);
	i = 0;
	size = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			size += ft_specifier(format[i], args);
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}

// int main()
// {
// 	int i = 31;
// 	printf("return: %i\n", ft_printf("string: %s\n", "hello"));
// 	printf("return: %i\n", ft_printf("string: %s\n", ""));
// 	printf("return: %i\n", ft_printf("int: %i%%\n", 14));
// 	printf("return: %i\n", ft_printf("char: %c\n", 'c'));
// 	printf("return: %i\n", ft_printf("hex: %x\n", 15));
// 	printf("return: %i\n", ft_printf("UPhex: %X\n", 15));
// 	printf("return: %i\n", ft_printf("unsigned: %u\n", -15));
// 	printf("return: %i\n", ft_printf("pointer: %p\n",&i));
// 	printf("return: %i\n", ft_printf("pointer: %p\n",NULL));
// 	printf("return: %i\n", printf("string: %s\n", "hello"));
// 	printf("return: %i\n", printf("string: %s\n", ""));
// 	printf("return: %i\n", printf("int: %i%%\n", 14));
// 	printf("return: %i\n", printf("char: %c\n", 'c'));
// 	printf("return: %i\n", printf("hex: %x\n", 15));
// 	printf("return: %i\n", printf("UPhex: %X\n", 15));
// 	printf("return: %i\n", printf("unsigned: %u\n", -15));
// 	printf("return: %i\n", printf("pointer: %p\n",&i));
// 	printf("return: %i\n", printf("pointer: %p\n",NULL));

// 	return 0;
// }
