/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 18:09:13 by moaks             #+#    #+#             */
/*   Updated: 2026/09/26 18:29:53 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_double(double n)
{
	int			i;
	int			count;
	long long	whole;
	double		frac;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	whole = (long long)n;
	frac = n - (double)whole;
	count += ft_putnbr(whole);
	count += ft_putchar('.');
	i = 0;
	while (i < 2)
	{
		frac *= 10;
		count += ft_putchar('0' + (int)frac % 10);
		i++;
	}
	return (count);
}
