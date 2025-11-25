/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:14:35 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/13 10:06:40 by mdourdoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (!haystack)
		return (NULL);
	if (!needle || needle[0] == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	if (len < needle_len)
		return (NULL);
	i = 0;
	while (haystack[i] && (i + needle_len <= len))
	{
		if (haystack[i] == needle[0]
			&& ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
