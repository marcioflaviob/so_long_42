/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:09:29 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/04 12:15:18 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_putunsnbr(unsigned int nb, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_putnbr_base(unsigned int n, int *counter, int type);
void	ft_putnbr_p(uintptr_t n, int *counter);
void	*ft_calloc(size_t count, size_t size);

#endif
