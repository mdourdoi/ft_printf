/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:35:22 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/05 11:11:36 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	ret_size;

	if (!nmemb || !size)
		ret_size = 1;
	else
		ret_size = nmemb * size;
	if (ret_size > 2147483647)
		return (NULL);
	ptr = malloc(ret_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, ret_size);
	return (ptr);
}
