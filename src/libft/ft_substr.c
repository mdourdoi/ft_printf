/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:37:53 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/13 10:02:16 by mdourdoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t n, size_t m)
{
	if (n > m)
		return (m);
	else
		return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*res;
	size_t	res_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		res = ft_calloc(1, sizeof(char));
		if (!res)
			return (NULL);
		return (res);
	}
	res_len = ft_min(len, s_len - start);
	res = ft_calloc(res_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < res_len)
		res[i] = s[i + start];
	return (res);
}
