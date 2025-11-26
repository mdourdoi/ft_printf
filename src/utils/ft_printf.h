/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:30:59 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/26 17:46:26 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen_upto(char const *s, char end);
int		ft_putnbr(ssize_t n, char *str_base, int base);
int		ft_voidp_writer(void *vp);
int		ft_putchar(char arg);
int		ft_putstr(char *arg);

#endif