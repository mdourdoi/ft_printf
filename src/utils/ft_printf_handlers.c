/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:54 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/26 15:06:49 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_voidp_writer(void *vp)
{
	int	ret;

	if (!vp)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ret = ft_putnbr_base((size_t)vp,"0123456789abcdef", 16) + 2;
	return (ret);
}

int	ft_putchar(void *arg)
{
	if (!arg)
		return (1);
	return (write(1, &arg, 1));
}

int ft_putstr(void *arg)
{
	if (!arg)
		return (write(1, "(null)", 6));
	return(write(1, arg, ft_strlen(arg)));
}