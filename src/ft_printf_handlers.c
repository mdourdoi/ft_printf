/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:54 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/27 18:02:04 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_voidp_writer(void *vp)
{
	if (!vp)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putnbr((ssize_t)vp, "0123456789abcdef", 16) + 2);
}

int	ft_putchar(char arg)
{

	return (write(1, &arg, 1));
}

int	ft_putstr(char *arg)
{
	if (!arg)
		return (write(1, "(null)", 6));
	return (write(1, arg, ft_strlen(arg)));
}
