/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:37 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/26 17:47:29 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

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

static ssize_t	ft_abs(ssize_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_putnbr(ssize_t n, char *str_base, int base)
{
	int	div;
	int	mod;
	int	ret;
	int	sign;

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
