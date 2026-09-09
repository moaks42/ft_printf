/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:41:32 by moaks             #+#    #+#             */
/*   Updated: 2026/09/09 20:17:52 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_hex(unsigned int i, char *digit, size_t base)
{
	int	count;

	count = 0;
	if (i >= base)
		count += ft_puthex(i / base, digit, base);
	return (count += ft_putchar(digit[i % base]));
}
