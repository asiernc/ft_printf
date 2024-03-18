/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:54:57 by anovio-c          #+#    #+#             */
/*   Updated: 2024/01/23 11:29:19 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int	ft_putz(int nb, char *str)
{
	if (nb == 0)
	{
		if (ft_putchar_pf('0') == -1)
			return (-1);
		else
			return (1);
	}
	else if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	return (nb);
}

int	ft_putnbr_pf(int nb)
{
	char	*str;
	int		len;

	len = ft_num_len(nb);
	if (nb == -2147483648)
		return (ft_putstr_pf("-2147483648"));
	if (nb == 0)
		return (ft_putz(nb, NULL));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	nb = ft_putz(nb, str);
	str[len--] = '\0';
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	len = ft_strlen_pf(str);
	if (ft_putstr_pf(str) == -1)
		len = -1;
	free(str);
	return (len);
}
