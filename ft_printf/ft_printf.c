/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:10 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/25 17:39:52 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ptr_print(unsigned long long n, int *counter)
{
	if (n == 0)
	{
		ft_putstr("(nil)", counter);
		return ;
	}
	else
	{
		ft_putstr("0x", counter);
		ft_putnbr_p(n, counter);
	}
}

static int	flag_dealer(va_list args, char c, int *counter)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (c == 'p')
		ptr_print(va_arg(args, unsigned long long), counter);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int), counter);
	else if (c == 'u')
		ft_putunsnbr(va_arg(args, unsigned int), counter);
	else if (c == 'x')
		ft_putnbr_base((unsigned int) va_arg(args, int), counter, 1);
	else if (c == 'X')
		ft_putnbr_base((unsigned int) va_arg(args, int), counter, 0);
	else if (c == '%')
		ft_putchar('%', counter);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	int		temp;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			ft_putchar(str[i++], &counter);
		if (str[i] == '%')
			temp = flag_dealer(args, str[++i], &counter);
		if (str[i] && temp)
			i++;
	}
	va_end(args);
	return (counter);
}
/*
int main()
{
	char *prompt = "a char: %c\nan int: %i\na hexa number: 
	%x\na hexa capital: %X\na string: %s\na percentage: 
	%%\nthe p: %p\nunsigned: %u";
	char *str = "test";
	unsigned int us = 2147483649;
	//int i = (printf("Hello %s %d", "123", 123));
	int i = printf(prompt, '$', 5242189, 17, 16, NULL, 0, us);
	//printf(prompt, '$', 5242189, 42, 42, str);
	printf("\n\n");
	int a = ft_printf(prompt, '$', 5242189, 17, 16, NULL, 0, us);
	printf("\n\n");
	printf("og = %i, mine = %i", i, a);
	return (0);
}
*/