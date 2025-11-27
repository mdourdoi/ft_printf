/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:37 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/27 19:00:53 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_upto(char const *s, char end)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != end)
			i++;
	}
	return (i);
}

size_t	ft_strlen(const char *c)
{
	size_t	res;

	res = 0;
	while (c[res])
		res++;
	return (res);
}

static size_t	ft_abs(size_t n)
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
		return (write(1, &str_base[mod], 1));
	ret = ft_putnbr(div, str_base, base);
	write(1, &str_base[mod], 1);
	return (ret + 1 + sign);
}

int	ft_putnbr_u(size_t n, char *str_base, size_t base)
{
	size_t	div;
	size_t	mod;
	size_t	ret;
	size_t	sign;

	sign = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		sign++;
	}
	div = ft_abs(n / base);
	mod = ft_abs(n % base);
	if (div == 0)
		return (write(1, &str_base[mod], 1));
	ret = ft_putnbr(div, str_base, base);
	write(1, &str_base[mod], 1);
	return (ret + 1 + sign);
}
