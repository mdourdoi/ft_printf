/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:29:04 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/27 19:00:33 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_upto(const char *s, char endchar)
{
	int	ret;

	ret = ft_strlen_upto(s, endchar);
	write(1, s, ret);
	return (ret);
}

static int	ft_handler(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (type == 'p')
		return (ft_voidp_writer(va_arg(args, size_t)));
	if (type == '%')
		return (write(1, "%", 1));
	if (type == 'i' || type == 'd')
		return (ft_putnbr(va_arg(args, ssize_t), "0123456789", 10));
	if (type == 'u')
		return (ft_putnbr_u(va_arg(args, size_t), "0123456789", 10));
	if (type == 'x')
		return (ft_putnbr(va_arg(args, size_t), "0123456789abcdef", 16));
	if (type == 'X')
		return (ft_putnbr(va_arg(args, size_t), "0123456789ABCDEF", 16));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		res;
	int		index;
	int		readed;

	if (!s)
		return (-1);
	va_start(args, s);
	index = 0;
	res = 0;
	readed = 0;
	while (s[index])
	{
		readed = ft_write_upto(&s[index], '%');
		res += readed;
		index += readed;
		if (!s[index])
			return (res);
		if (s[index + 1])
		{
			res += ft_handler(s[index + 1], args);
			index += 2;
		}
	}
	return (res);
}

#include <limits.h>
#include <stdio.h>
int main()
{
	int i = ft_printf("%d", -1);
	printf("\n");
	int j = printf("%d", -1);
	printf("\n %i %i", i, j);
}