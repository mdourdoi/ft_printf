/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_voidp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:37 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/28 16:20:06 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putvoidp(size_t n, char *str_base, size_t base)
{
	size_t	div;
	size_t	mod;
	size_t	ret;

	div = n / base;
	mod = n % base;
	if (div == 0)
		return (write(1, &str_base[mod], 1));
	ret = ft_putvoidp(div, str_base, base);
	write(1, &str_base[mod], 1);
	return (ret + 1);
}

int	ft_voidp_writer(size_t vp)
{
	if (!vp)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putvoidp(vp, "0123456789abcdef", 16) + 2);
}
