/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:49:35 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/13 10:02:31 by mdourdoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;

	if (fd < 0)
		return ;
	if (n < 0)
		ft_putchar_fd('-', fd);
	div = ft_abs(n / 10);
	mod = ft_abs(n % 10);
	if (div == 0)
	{
		ft_putchar_fd(mod + '0', fd);
		return ;
	}
	ft_putnbr_fd(div, fd);
	ft_putchar_fd(mod + '0', fd);
}
