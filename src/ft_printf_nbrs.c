/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:37 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/01 10:46:30 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnb(int n, char *str_base, int base)
{
	int		div;
	int		mod;
	int		ret;
	int		sign;
	long	nb;

	nb = n;
	sign = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		sign++;
	}
	div = nb / base;
	mod = nb % base;
	if (div == 0)
		return (write(1, &str_base[mod], 1) + sign);
	ret = ft_putnb(div, str_base, base);
	write(1, &str_base[mod], 1);
	return (ret + 1 + sign);
}
