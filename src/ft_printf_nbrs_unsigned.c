/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:37 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/28 16:08:07 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnb_u(unsigned int n, char *str_base, unsigned int base)
{
	unsigned int	div;
	unsigned int	mod;
	unsigned int	ret;

	div = n / base;
	mod = n % base;
	if (div == 0)
		return (write(1, &str_base[mod], 1));
	ret = ft_putnb_u(div, str_base, base);
	write(1, &str_base[mod], 1);
	return (ret + 1);
}
