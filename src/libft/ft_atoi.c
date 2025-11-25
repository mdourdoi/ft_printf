/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:09:20 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/12 13:27:29 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(char c)
{
	if (((c >= 9) && (c <= 13)) || (c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t			i;
	int				sign;
	long int		res;

	if (!nptr)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	while (ft_is_whitespace(nptr[i]))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		res = res * 10 + (long int)(nptr[i++] - '0');
	return (sign * res);
}
