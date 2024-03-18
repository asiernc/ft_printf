/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:04:29 by anovio-c          #+#    #+#             */
/*   Updated: 2024/01/20 16:26:01 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int num, char const fmt)
{
	if (fmt == 'x')
	{
		return (ft_format_hex(num, "0123456789abcdef"));
	}
	else
	{
		return (ft_format_hex(num, "0123456789ABCDEF"));
	}
}
