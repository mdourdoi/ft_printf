/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:29:04 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/25 15:50:04 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	ft_write_upto(char *s, void *content)
{
	
}

int	ft_printf(const char *s, ...)
{
	va_list	args;

	if (!s)
		return (-1);
	va_start(args, s);
	
}