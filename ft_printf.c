/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:05:52 by anovio-c          #+#    #+#             */
/*   Updated: 2024/01/26 11:08:25 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatter(va_list args, char const fmt)
{
	if (fmt == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	else if (fmt == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (fmt == 'p')
		return (ft_putadress_pf(va_arg(args, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_putnbr_pf(va_arg(args, int)));
	else if (fmt == 'u')
		return (ft_putunsigned_pf(va_arg(args, unsigned int)));
	else if (fmt == 'x' || fmt == 'X')
		return (ft_puthex_pf(va_arg(args, unsigned int), fmt));
	else if (fmt == '%')
		return (ft_putchar_pf('%'));
	else
		return (-1);
}

static int	ft_check(va_list args, char const *fmt)
{
	int	tmp;
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%' && ft_strchr_pf("cspdiuxX%", *(fmt + i + 1)))
		{
			tmp = ft_formatter(args, *(fmt + i + 1));
			if (tmp == -1)
				return (-1);
			i++;
			len += tmp;
		}
		else
		{
			if (ft_putchar_pf(*(fmt + i)) == -1)
				return (-1);
			len += 1;
		}
		i++;
	}
	return (len);
}

int	ft_printf(char const *fmt, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, fmt);
	len = ft_check(args, fmt);
	va_end(args);
	return (len);
}
/*
#include <stdio.h>

int main(void)
{
	char	i = '1';
	int		d1 = -1;
	int		d2 = -30;
	int		len = 0;
	int		test = -345;
	void	*ptrnull = NULL;
	void	*str = "asier";
	char	*str1 = "  Hola   Adios!! @#$%^";
	int		len1 = 0;
	unsigned int	testhex = 2345678;
	int		lenhex1 = 0;
	int		lenhex2 = 0;
	unsigned int	unsig = -345;
	int	lentest = 0;

	lentest = ft_printf("%p", ptrnull);
	ft_printf("%d", lentest);

	ft_printf("D1: %d", d1);
	ft_printf("\nD2: %d\n", d2);

	len = ft_printf("%c: %s..%d\n",i, str, test);
	//ft_printf("%c: %s..%d\n", i, str, test);
	printf("%d\n", len);
	ft_printf("   ..%s\n", str1);
	printf("Test ptr null:\n OK: %p\n", ptrnull);
	printf("Own: %p\n", ptrnull);
	ft_printf("Pointer Test: \n");
	printf("OK: %p\n", (void *)str);
	len1 = ft_printf("1Own: %p\n", (void *)str);
	ft_printf("%d", len1);
   	ft_printf("\n");
	printf("OK: %x\n", testhex);
	lenhex1 = ft_printf("Own: %x\n", testhex);
	ft_printf("Length - 6: %d\n", lenhex1);
	printf("OK: %X\n", testhex);
	lenhex2 = ft_printf("Own: %X\n", testhex);
	ft_printf("Length - 6: %d\n", lenhex2);
	printf("%u\n", unsig);
	ft_printf("%u\n", unsig);
	ft_printf("Test %: %%%s", str);

	return (0);
}*/
