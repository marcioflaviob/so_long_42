/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:36 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 19:06:09 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-', counter);
		nb = n * -1;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr((nb / 10), counter);
		ft_putnbr((nb % 10), counter);
	}
	else
		ft_putchar((nb + 48), counter);
}
