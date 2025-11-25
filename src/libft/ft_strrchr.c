/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:16:48 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/06 16:07:30 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t	len;

	len = ft_strlen(src);
	while (len != 0)
	{
		if ((unsigned char)src[len] == (unsigned char)c)
			return ((char *)&src[len]);
		len--;
	}
	if ((unsigned char)src[0] == (unsigned char)c)
		return ((char *)src);
	return (NULL);
}
