/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:30 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 19:07:35 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_p(uintptr_t n, int *counter)
{
	char			*base;
	unsigned int	base_size;

	base = "0123456789abcdef";
	base_size = 16;
	if (n >= base_size)
	{
		ft_putnbr_p((n / base_size), counter);
		ft_putnbr_p((n % base_size), counter);
	}
	else
		ft_putchar(base[n], counter);
}
/*
int		main(void)
{
	int a = 1;
	int *i = &a;
	ft_putnbr_base(16, i, 1);
	ft_putnbr_base(17, i, 1);
	return (0);
}
*/