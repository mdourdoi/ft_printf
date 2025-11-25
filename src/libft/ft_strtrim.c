/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:50:33 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/13 09:54:38 by mdourdoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_inset(char c, char const *set)
{
	size_t	i;
	size_t	lenset;

	i = 0;
	lenset = ft_strlen(set);
	while (i < lenset)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_is_inset(s1[i], set) && s1[i])
		i++;
	return (i);
}

static int	ft_get_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (ft_is_inset(s1[i], set) && i > 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	if (start > end)
	{
		res = ft_calloc(1, sizeof(char));
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_calloc(end - start + 2, sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < end - start + 1)
		res[i] = s1[i + start];
	return (res);
}
