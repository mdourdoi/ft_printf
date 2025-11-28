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

int	ft_putnbr_u(size_t n, char *str_base, size_t base)
{
	size_t	div;
	size_t	mod;
	size_t	ret;

	div = n / base;
	mod = n % base;
	if (div == 0)
		return (write(1, &str_base[mod], 1));
	ret = ft_putnbr(div, str_base, base);
	write(1, &str_base[mod], 1);
	return (ret + 1);
}
