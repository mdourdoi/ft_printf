/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:33:31 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/13 10:01:15 by mdourdoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_emergency_free(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	res;

	if ((!s) || (!s[0]))
		return (0);
	res = 0;
	if (s[0] != c)
		res++;
	i = 1;
	while (s[i])
	{
		if ((s[i - 1] == c) && (s[i] != c))
			res++;
		i++;
	}
	return (res);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] != c) && (s[i]))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	iter_words;
	size_t	track;

	res = ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if ((!res) || (!s))
		return (NULL);
	iter_words = 0;
	track = 0;
	while ((s[track] == c))
		track++;
	while (iter_words < ft_countwords(s, c))
	{
		res[iter_words] = ft_substr(s, track, ft_wordlen(&s[track], c));
		if (!res[iter_words])
			return (ft_emergency_free(res, iter_words + 1));
		track += ft_wordlen(&s[track], c) + 1;
		while ((s[track] == c) && s[track])
			track++;
		iter_words++;
	}
	return (res);
}
