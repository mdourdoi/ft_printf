/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:54 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/28 16:20:17 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
