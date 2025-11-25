/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:50:08 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/13 10:02:04 by mdourdoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_join(char const *s)
{
	if (!s)
		return (0);
	return (ft_strlen(s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	len_s1 = ft_strlen_join(s1);
	len_s2 = ft_strlen_join(s2);
	res = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (i < len_s1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		res[i + len_s1] = s2[i];
		i++;
	}
	return (res);
}
