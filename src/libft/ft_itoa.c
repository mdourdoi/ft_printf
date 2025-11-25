/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:15:00 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/13 10:01:36 by mdourdoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_intlen(int n)
{
	if (n == (-2147483648))
		return (11);
	if (n < 0)
		return (1 + ft_intlen(-n));
	if (n / 10 == 0)
		return (1);
	return (1 + ft_intlen(n / 10));
}

char	*ft_itoa(int n)
{
	int		i;
	int		res_len;
	int		len;
	char	*res;

	res_len = ft_intlen(n);
	if (n == -2147483648)
		len = 10;
	else
		len = ft_intlen(ft_abs(n));
	res = ft_calloc(res_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
		res[0] = '-';
	while (i < len)
	{
		res[res_len - i++ - 1] = ft_abs(n % 10) + '0';
		n = ft_abs(n / 10);
	}
	return (res);
}
