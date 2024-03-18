/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:57:16 by anovio-c          #+#    #+#             */
/*   Updated: 2024/01/22 15:53:06 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress_pf(void *ptr)
{
	unsigned long long	n;
	int					len;
	int					func;

	n = (unsigned long)ptr;
	len = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	func = ft_format_hex(n, "0123456789abcdef");
	if (func == -1)
		return (-1);
	return (len + func);
}
