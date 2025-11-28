/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:37 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/28 16:02:36 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_abs(ssize_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_putnbr(ssize_t n, char *str_base, ssize_t base)
{
	ssize_t	div;
	ssize_t	mod;
	ssize_t	ret;
	ssize_t	sign;

	sign = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		sign++;
	}
	div = ft_abs(n / base);
	mod = ft_abs(n % base);
	if (div == 0)
		return (write(1, &str_base[mod], 1) + sign);
	ret = ft_putnbr_u(div, str_base, base);
	write(1, &str_base[mod], 1);
	return (ret + 1 + sign);
}
