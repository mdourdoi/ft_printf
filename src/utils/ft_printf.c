/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:29:04 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/26 15:24:27 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	ft_write_upto(const char *s, char endchar)
{
	int	ret;

	ret = ft_strlen_upto(s, endchar);
	write(1, s, ret);
	return (ret);
}

static int ft_handler(char type, void *arg)
{
	if (type == 'c')
		return (ft_putchar(arg));
	if (type == 's')
		return (ft_putstr(arg));
	if (type == 'p')
		return (ft_voidp_writer(arg));
	if (type == '%')
		return (write(1, "%", 1));
	if (!arg)
		return (write(1, "0", 1));
	if (type == 'i' || type == 'd')
		return (ft_putnbr_base((int)arg, "0123456789", 10));
	if (type == 'u')
		return (ft_putnbr_base((unsigned int)arg, "0123456789", 10));
	if (type == 'x')
		return (ft_putnbr_base((unsigned int)arg, "0123456789abcdef", 10));
	if (type == 'X')
		return (ft_putnbr_base((unsigned int)arg, "0123456789ABCDEF", 10));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		index;

	if (!s)
		return (-1);
	va_start(args, s);
	index = 0;
	index += ft_write_upto(s, '%') + 1;
	if (!s[index - 1])
		return (index - 1);
	if (s[index])
		ft_handler(s[index], va_arg(args, void *));
	return (0);
}

int main()
{
	void *test;
	
	printf("test %x", -218);
	printf("\n");
	ft_printf("test %x", -218);
	return (0);
}