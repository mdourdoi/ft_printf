/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:12:06 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/13 10:02:41 by mdourdoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*reverse_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = n;
	while (i > 0)
	{
		((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if ((dest == src) || (n == 0))
		return (dest);
	if ((unsigned char *)dest < (unsigned char *)src)
		ft_memcpy(dest, src, n);
	else
		reverse_memcpy(dest, src, n);
	return (dest);
}
