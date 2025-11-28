/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:37 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/28 16:20:11 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_upto(char const *s, char end)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != end)
			i++;
	}
	return (i);
}

size_t	ft_strlen(const char *c)
{
	size_t	res;

	res = 0;
	while (c[res])
		res++;
	return (res);
}
